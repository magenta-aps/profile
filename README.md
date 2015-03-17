# Installation
This README assumes that you have install a configured your server with a
working Apache/Nginx. The stack should be optimized to run a Drupal site.

## Dependencies
* [Drush 6.1.0](https://github.com/drush-ops/drush)

# Production
```sh
  ~$ drush make https://raw.github.com/os2loop/profile/master/drupal.make loop
```

# Development
If you want a developer version with _working copies_ of the Git repositories,
run this command instead.

```sh
  ~$ drush make --working-copy https://raw.github.com/os2loop/profile/development/drupal.make loop
```

## Apache Solr
If you have an Apache Solr on your local dev environment you should name the core: 'loop_stg' for seamless integration.

## Setting up LOOP
After running the make file you should install the site as any other Drupal website.
By default only the core features are enabled so you should visit the features overview and enable any additional features you would need.

### Setup for development
Enable the Loop example content feature and create a demo user account.
You can drush dl and drush en the Devel module and use this for generating content.
