<?php

/**
 * @file
 * Wrapper class that extend SoapClient.
 */

/**
 * Class AgriProjectsSfcWs.
 */
class AgriProjectsSfcWs extends SoapClient {

  /**
   * Default SOAPClient::__construct options used by the class.
   *
   * @var array
   */
  protected $options = array(
    'connection_timeout' => 30,
    'exceptions' => TRUE,
    'cache_wsdl' => WSDL_CACHE_NONE,
  );

  /**
   * Class construct.
   *
   * @param mixed $wsdl
   *   URI of the WSDL file.
   * @param mixed $options
   *   An array of options.
   */
  public function __construct($wsdl, $options) {

    // Get SFC certificate.
    $settings = variable_get('sfc_soap_ws', array());
    if (!empty($settings)) {
      $options += array(
        'local_cert' => $settings['local_cert'],
      );

      if (isset($settings['local_cert_passphrase']) && !empty($settings['local_cert_passphrase'])) {
        $options += array(
          'passphrase' => $settings['local_cert_passphrase'],
        );
      }
    }

    // Get proxy settings from settings.php.
    $options += array(
      'proxy_host' => variable_get('proxy_server', ''),
      'proxy_port' => variable_get('proxy_port', ''),
    );

    if ($proxy_username = variable_get('proxy_username', FALSE)) {
      $options += array(
        'proxy_login' => $proxy_username,
      );
    }

    if ($proxy_password = variable_get('proxy_password', FALSE)) {
      $options += array(
        'proxy_password' => $proxy_password,
      );
    }

    $options += $this->options;

    parent::__construct($wsdl, $options);
  }

  /**
   * Call search method of the SFC2014 service.
   *
   * @param array|null $query
   *   Parameter of the method search.
   * @param bool $debug_mode
   *   A flag for the debug mode.
   *
   * @return array
   *   Return an array of project ids not yet worked. If $debug_mode is TRUE,
   *   return the entire response.
   */
  public function searchProject($query = array(), $debug_mode = FALSE) {

    $projects = array();
    $param = array(
      'query' => $query,
    );
    $response = $this->__soapCall('search', array($param));

    if ($debug_mode) {
      return $response;
    }

    $data = $response->return;

    $count = 0;
    if ($data->size != 0) {
      foreach ($data->resultList as $result) {
        $modification_date = $this->getModificationDate($result);
        if ($modification_date > variable_get('agri_projects_sfc_ws_last_time', 0)) {
          $cci = $this->getCciFromResponse($result);
          $projects[] = $cci;
          $count++;
        }
      }
    }

    watchdog('agri_projects_sfc_ws', '@count project/s of @total need/s to be added to the queue since @date.', array(
      '@count' => $count,
      '@total' => $data->size,
      '@date' => format_date(variable_get('agri_projects_sfc_ws_last_time', 0), 'custom', 'd M Y H:i:s'),
    ), WATCHDOG_INFO);

    return $projects;
  }

  /**
   * Call read method of the SFC2014 service.
   *
   * @param mixed $param
   *   An array(
   *     'cci' => array (The project identifier)
   *     'version' => string (The project version)
   *     'workVersion' => string (The project workVersion)
   *   ).
   *
   * @return mixed
   *   Return the full project from SFC2014 service.
   */
  public function readProject($param) {
    $data = $this->__soapCall('read', array($param));
    return $data;
  }

  /**
   * Call getReferenceData method of the SFC2014 service.
   *
   * @param string $name
   *   The name of the vocabulary.
   *
   *   Example: EipAgriPartnerType, EipAgriFundingSource, EipAgriKeyword.
   *
   * @return array
   *   The full vocabulary.
   */
  public function getDictionary($name) {
    $param = array(
      'name' => $name,
    );
    $data = $this->__soapCall('getReferenceData', array($param));
    return (array) $data->return;
  }

  /**
   * Private function that return the cci from response.
   *
   * @param object $response
   *   The response from SFC2014 service.
   *
   * @return array
   *   The cci of the SFC project.
   */
  private function getCciFromResponse($response) {
    $cci = get_object_vars($response->s0->s0_ver->cci);
    return $cci;
  }

  /**
   * Return modification date in Unix timestamp.
   *
   * @param object $response
   *   The response from SFC2014 service.
   *
   * @return int
   *   Unix timestamp.
   */
  private function getModificationDate($response) {
    $s0_ver = get_object_vars($response->s0->s0_ver);
    if (isset($s0_ver['modificationDate'])) {
      $modification_date = strtotime($s0_ver['modificationDate']);
      return $modification_date;
    }
  }

}

/**
 * Class AgriProjectsSfcWsSystemQueue.
 */
class AgriProjectsSfcWsSystemQueue extends SystemQueue {

  /**
   * Enable or not the queue.
   *
   * @inheritdoc
   */
  public function claimItem($lease_time = 30) {
    if (variable_get('agri_projects_sfc_ws_enable', FALSE)) {
      return parent::claimItem($lease_time);
    }
    else {
      return FALSE;
    }
  }

}
