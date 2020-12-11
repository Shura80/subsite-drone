<?php

namespace Drupal\enrd_sfr\Controller;

use EntityDefaultMetadataController;

/**
 * Extend the default Controller for generating Enrd Sfr basic metadata.
 */
class EnrdSfrMetadataController extends EntityDefaultMetadataController {

  /**
   * Extend default Entity Property Info.
   */
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['sfrid'] = array(
      'label' => t('ENRD Sfr unique id'),
      'type' => 'integer',
      'description' => t('The primary identifier for the ENRD Sfr.'),
      'schema field' => 'sfrid',
    );
    $properties['type'] = array(
      'label' => t('Bundle type'),
      'description' => t('The bundle type of the ENRD Sfr entity.'),
      'setter callback' => 'entity_property_verbatim_set',
      'getter callback' => 'entity_property_verbatim_get',
      'sanitize' => 'filter_xss',
      'type' => 'token',
      'schema field' => 'type',
      'required' => TRUE,
    );
    $properties['created'] = array(
      'label' => t('Created'),
      'description' => t('The Unix timestamp when the ENRD Sfr was created.'),
      'type' => 'date',
      'schema field' => 'created',
    );
    $properties['finalized'] = array(
      'label' => t('Finalized'),
      'description' => 'The Unix timestamp when the ENRD Sfr was finalized.',
      'setter callback' => 'entity_property_verbatim_set',
      'getter callback' => 'entity_property_verbatim_get',
      'type' => 'date',
      'schema field' => 'finalized',
    );
    $properties['status'] = array(
      'label' => t('Status'),
      'description' => t('ENRD Sfr status (Finalized/Not finalized).'),
      'setter callback' => 'entity_property_verbatim_set',
      'getter callback' => 'entity_property_verbatim_get',
      'type' => 'integer',
      'schema field' => 'status',
    );

    return $info;
  }

}
