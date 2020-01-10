<?php

namespace Drupal\enrd_sfr\Views;

/**
 * Class EnrdSfrViewsController.
 */
class EnrdSfrViewsController extends \EntityDefaultViewsController {

  /**
   * Add custom extra fields to views_data().
   */
  public function views_data() {
    $data = parent::views_data();

    /*
     * Set "Finalized" timestamp field/filter/sort views date handlers.
     */
    $data['enrd_sfr']['finalized']['field']['handler'] = 'views_handler_field_date';
    $data['enrd_sfr']['finalized']['field']['click sortable'] = TRUE;
    $data['enrd_sfr']['finalized']['filter']['handler'] = 'date_views_filter_handler_simple';
    $data['enrd_sfr']['finalized']['filter']['allow empty'] = TRUE;
    $data['enrd_sfr']['finalized']['sort']['handler'] = 'views_handler_sort_date';
    $data['enrd_sfr']['finalized']['argument']['handler'] = 'views_handler_argument_date';

    return $data;
  }

}
