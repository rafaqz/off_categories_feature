<?php
/**
 * @file
 * categories_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function categories_feature_field_default_field_instances() {
  $field_instances = array();

  // Get a list of content types that should have the field_topics field added.
  $entity_types = categories_feature_get_entity_types_with_categories();
  if (!empty($entity_types)) {
    foreach ($entity_types as $entity_type => $bundles) {
      foreach(array_keys($bundles) as $bundle) {
        categories_feature_field_definition($field_instances, $entity_type, $bundle);
      }
    }
  }

  // Translatables
  // Included for use with string extractors like potx.
  t('Categories');

  return $field_instances;
}


function categories_feature_field_definition(&$field_instances, $entity_type, $bundle) {
  // Exported field_instance: 'ENTITY_TYPE-BUNDLE-field_categories'
  $field_instances["$entity_type-$bundle-field_categories"] = array(
    'bundle' => $bundle,
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Categorise content',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
    ),
    'entity_type' => $entity_type,
    'field_name' => 'field_categories',
    'label' => 'Categories',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 5,
    ),
  );
}
