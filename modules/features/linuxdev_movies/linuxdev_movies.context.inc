<?php
/**
 * @file
 * linuxdev_movies.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function linuxdev_movies_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'movie';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'movies' => 'movies',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-Lc0A0EIRrPDt5gnq4SuURi5uPiv1OEPe' => array(
          'module' => 'facetapi',
          'delta' => 'Lc0A0EIRrPDt5gnq4SuURi5uPiv1OEPe',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-V0Dq1x4xf7iS6Cb0BhjhgpU3UhBlBiUQ' => array(
          'module' => 'facetapi',
          'delta' => 'V0Dq1x4xf7iS6Cb0BhjhgpU3UhBlBiUQ',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-U1IMGH9bkq3CzuOtf8yiRAZKpcS2kIfp' => array(
          'module' => 'facetapi',
          'delta' => 'U1IMGH9bkq3CzuOtf8yiRAZKpcS2kIfp',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['movie'] = $context;

  return $export;
}
