# Loop SimpleSAMLphp

This module allows users to authenticate to Loop using SAML when
SimpleSAMLphp has been properly installed and configured.

It redirects users to the SAML login page instead of allowing them to login 
using the normal Drupal login form (unless you visit the /user/login page).

It also provides a way to map SAML attributes to Loop user profile fields from
the SimpleSAMLphp Auth configuration page.

# Installation and configuration

1.  [Download SimpleSAMLphp](https://simplesamlphp.org/download).

2.  Follow the guide to [configure SimpleSAMLphp as a Service Provider](https://simplesamlphp.org/docs/stable/simplesamlphp-sp).
      
3.  Your SimpleSAMLphp SP must be configured to use something other than
    "phpsession" (the default) for session storage. The alternatives are memcache
    or sql. The sql option was added in SimpleSAMLphp version 1.7.
    The simplest solution for folks running SimpleSAMLphp version 1.7 or higher is
    to edit the SimpleSAMLphp `config/config.php` by setting `store.type => 
    'sql'` and `'store.sql.dsn' => 'sqlite:/path/to/sqlitedatabase.sq3'`

4.  Enable this module.

5.  Configure and activate the `simplesamlphp_auth` module at 
    `/admin/config/people/simplesamlphp_auth`
    At the bottom of the page, SAML attributes can be mapped to Loop user
    profile fields. Defaults are provided. If you would not like to map
    certain attributes, then leave them blank.
