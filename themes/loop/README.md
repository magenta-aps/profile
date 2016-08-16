Loop theme
==========

This repository is the default theme for the Loop web application.

Sass is based on ITK Designs boilerplate found here, https://github.com/aakb/frontend-boilerplate


Building the stylesheet
-----------------------

First, install requirements:

```
bower install
npm install
```

Then build the stylesheet by running this command

```
gulp sass
```

To continuosly update the stylesheet when editing the source scss files you can run

```
gulp watch sass
```

Add `--env=dev` to the command to include source maps in the generated stylesheet:

```
gulp watch sass --env=dev
```

Finally, you should build the stylesheet for production like this
```
gulp build
```
