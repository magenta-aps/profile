<?php
/**
 * @file
 * loop_user.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function loop_user_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_areas_of_expertise|user|user|default';
  $field_group->group_name = 'group_areas_of_expertise';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Areas of expertise',
    'weight' => '5',
    'children' => array(
      0 => 'field_area_of_expertise',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Areas of expertise',
      'instance_settings' => array(
        'classes' => 'user-profile-module--field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_areas_of_expertise|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|user|user|default';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '7',
    'children' => array(
      0 => 'field_biography',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Description',
      'instance_settings' => array(
        'classes' => 'user-profile-module--field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_description|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_title|user|user|default';
  $field_group->group_name = 'group_job_title';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Job title',
    'weight' => '3',
    'children' => array(
      0 => 'field_job_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Job title',
      'instance_settings' => array(
        'classes' => 'user-profile-module--field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_job_title|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|user|user|default';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '6',
    'children' => array(
      0 => 'field_location_address',
      1 => 'field_location_city',
      2 => 'field_location_place',
      3 => 'field_location_postal_code',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Location',
      'instance_settings' => array(
        'classes' => 'user-profile-module--field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_location|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|user|user|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_work_related_information';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '50',
    'children' => array(
      0 => 'field_location_address',
      1 => 'field_location_city',
      2 => 'field_location_place',
      3 => 'field_location_postal_code',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Location',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_location|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal_information|user|user|default';
  $field_group->group_name = 'group_personal_information';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal information',
    'weight' => '2',
    'children' => array(
      0 => 'field_first_name',
      1 => 'field_last_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Personal information',
      'instance_settings' => array(
        'classes' => 'user-profile-module--field-group-fieldset-personal-info',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_personal_information|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal_information|user|user|form';
  $field_group->group_name = 'group_personal_information';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal information',
    'weight' => '0',
    'children' => array(
      0 => 'field_first_name',
      1 => 'field_last_name',
      2 => 'field_phone_number',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Personal information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'user-profile-module--field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_personal_information|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_picture|user|user|form';
  $field_group->group_name = 'group_picture';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Picture',
    'weight' => '3',
    'children' => array(
      0 => 'field_user_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Picture',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'user-profile-module--field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_picture|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profession|user|user|default';
  $field_group->group_name = 'group_profession';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profession',
    'weight' => '4',
    'children' => array(
      0 => 'field_profession',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Profession',
      'instance_settings' => array(
        'classes' => 'user-profile-module--field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_profession|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_work_related_information|user|user|form';
  $field_group->group_name = 'group_work_related_information';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Work related information',
    'weight' => '1',
    'children' => array(
      0 => 'field_area_of_expertise',
      1 => 'field_job_title',
      2 => 'field_profession',
      3 => 'group_location',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Work related information',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'user-profile-module--field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_work_related_information|user|user|form'] = $field_group;

  return $export;
}
