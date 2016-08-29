'use strict';

var argv = require('yargs')
    .describe('env', 'Environment to process (dev, test, prod)')
    .default('env', 'prod')
    .help('h')
    .alias('h', 'help')
    .epilog('copyright 2015')
    .argv;
var gulp = require('gulp');

// Plugins.
var sass = require('gulp-sass');
var replace = require('gulp-replace');

var sourcemaps = require('gulp-sourcemaps');
var gulpif = require('gulp-if');

// We only want to process our own non-processed JavaScript files.
var sassPath = './sass/**/*.scss';

var devMode = argv.env == 'dev';

console.log(devMode);

/**
 * Process SCSS using libsass
 */
gulp.task('sass', function () {
  gulp.src(sassPath)
    .pipe(sourcemaps.init())
    .pipe(sass({
      outputStyle: 'nested',
      includePaths: [
        'node_modules/compass-mixins/lib',
        'bower_components/zen-grids/stylesheets'
      ]
    }).on('error', sass.logError))
    .pipe(gulpif(devMode, sourcemaps.write()))
  // Replace some comments (/*! with /*) to support https://www.drupal.org/project/style_settings.
    .pipe(replace(new RegExp('(/*)!(\\s*(?:setting\|variable):)', 'g'), '$1$2'))
    .pipe(gulp.dest('./css'));
});

/**
 * Watch files for changes and run tasks.
 */
gulp.task('watch', function() {
  gulp.watch(sassPath, [ 'sass' ]);
});

// Tasks to compile sass and watch.
gulp.task('default', [ 'sass', 'watch' ]);

gulp.task('build', [ 'sass']);
