# Installation
This README assumes that you are running a Debian based system and have configured your server with a working Apache/Nginx & MySQL. The stack should be optimized to run a Drupal site.

Loop uses [Apache Solr](http://lucene.apache.org/solr/) for searching (and indexing) content using the "[Search API Solr Search](https://www.drupal.org/project/search_api_solr)" module. See the section on Apache Solr for installation instructions.

For installation and setup you should have drush and unzip installed, if not run:
```
sudo apt-get install drush
sudo apt-get install unzip
```

## Important post-installation notes

Check out the notes on the [Loop saml](modules/loop_saml/README.md) module if it's installed.

## Upgrading existing Loop installations

See
[Upgrading an old Loop installation](https://github.com/os2loop/upgrading-loop/blob/master/README.md)
for details on how to upgrade existing Loop installations.

## Dependencies
* Apache/Nginx
* MySQL/MariaDB/Etc.
* Apache Solr
* [Drush 6.1.0](https://github.com/drush-ops/drush)
* Unzip (used by the make-files)

## Production
```
drush make https://raw.github.com/os2loop/profile/master/drupal.make htdocs
```

## Development
If you want a developer version with _working copies_ of the Git repositories,
run this command instead.

```
drush make --working-copy https://raw.github.com/os2loop/profile/develop/drupal.make htdocs
```


## Installing Loop

After running the make file you should install the site as any other Drupal website.
First, create a database (loop) and a database user (loop) with access to the database or use an exiting database.

```
mysql --user=root --password --host=localhost
[enter root password]
create database `loop`;
create user 'loop'@'localhost' identified by 'loop';
grant all privileges on `loop`.* to 'loop'@'localhost';
quit
```

Then install Drupal either by visiting the site or using drush.

Now you can sign into Loop with the admin credentials you selected during install.

By default only the core features are enabled so you should visit the features overview and enable any additional features you would need.


### Setup for development

Enable the Loop example content feature and create a demo user account.

Download and enable the Devel module and use this for generating content:

```
drush --yes dl devel
drush --yes pm-enable devel_generate
```

Create taxonomi terms like this:

```
drush generate-terms keyword 10
drush generate-terms profession 10
drush generate-terms subject 10
```

Create 10 posts with (at most) 2 comment each like this:

```
drush generate-content --types=post 10 2
```

## Apache Solr

Loop uses [Apache Solr](http://lucene.apache.org/solr/) for searching (and indexing) content using the "[Search API Solr Search](https://www.drupal.org/project/search_api_solr)" module.

The default Solr server settings are

```
  host: localhost
  port: 8983
  path: /solr/loop
```

After installing Loop these settings should be changed to match the actual Solr server setup (go to `/admin/config/search/search_api`)
and edit the server named "Default").

See [Installing Apache Solr](#installing-apache-solr) below for details on how to get Solr up and running on your server.


## Adding taxonomies

After installing the Loop profile you should create some taxomony terms in the vocabularies Keyword, Profession and Subject. At lease one term must be defined in the Subject vocabulary before users can create new posts.

Go to `/admin/structure/taxonomy` to add terms to the vocabularies.

As an alternative to manually creating terms, you can install the module [Loop taxonomy terms (loop_taxonomy_terms)](/admin/modules#loop_content) and get the default Loop taxonomy terms.

## Installing Apache Solr

These script below will

* install Apache Solr 4.9.1 (as a Tomcat servlet) running on port 8983 and
* create a Solr core named "loop"

Change "8983" and "loop" as needed.

```
# Install tomcat7 and Java 7
sudo apt-get update
sudo apt-get install -y tomcat7 openjdk-7-jre

# Make Tomcat run on post 8983 (rather than 8080)
sudo sed --in-place '/\<Connector port="8080" protocol="HTTP\/1.1"/c \<Connector port="8983" protocol="HTTP\/1.1"' /var/lib/tomcat7/conf/server.xml

# Make Tomcat use Java 7
sudo sed --in-place 's@.*JAVA_HOME.*@JAVA_HOME=/usr/lib/jvm/java-7-openjdk-amd64@' /etc/default/tomcat7

# Restart tomcat
sudo service tomcat7 restart

# Check that tomcat is running (expect "HTTP/1.1 200 OK")
curl --head http://localhost:8983/

# Install Solr
cd ~
wget http://archive.apache.org/dist/lucene/solr/4.9.1/solr-4.9.1.tgz -O solr.tgz
tar xzf solr.tgz
rm solr.tgz
sudo cp solr-*/example/lib/ext/* /usr/share/tomcat7/lib/
sudo cp solr-*/dist/solr-*.war /var/lib/tomcat7/webapps/solr.war
sudo cp -R solr-*/example/solr /var/lib/tomcat7
rm -rf solr-*
cd -

# Set file permissions
sudo chown -R tomcat7:tomcat7 /var/lib/tomcat7/solr

# Restart tomcat
sudo service tomcat7 restart

# Check that solr is running on tomcat (expect "HTTP/1.1 200 OK")
curl --head http://localhost:8983/solr/
```

## Adding a Solr core

The first Loop Solr core can be created like this

```
# Create Solr core "loop"
sudo cp -r /var/lib/tomcat7/solr/collection1 /var/lib/tomcat7/solr/loop
sudo sed -i 's/collection1/loop/' /var/lib/tomcat7/solr/loop/core.properties

# Get Drupal Solr configuration and copy it into the Solr installion
cd ~
drush pm-download search_api_solr
sudo cp search_api_solr/solr-conf/4.x/* /var/lib/tomcat7/solr/loop/conf/
rm -rf search_api_solr
cd -

# Set file permissions
sudo chown -R tomcat7:tomcat7 /var/lib/tomcat7/solr

# Restart tomcat
sudo service tomcat7 restart

# Check that Solr is running and that we can access the core "loop" (expect "HTTP/1.1 200 OK")
curl --head 'http://localhost:8983/solr/loop/select?q=*%3A*&wt=json&indent=true'
```

Additional Loop Solr cores can be created as shown above or be created
as copies of already existing cores:

```
# Create Solr core "loop_custom" as a copy of "loop"
sudo cp -r /var/lib/tomcat7/solr/loop /var/lib/tomcat7/solr/loop_custom
sudo sed -i 's/loop/loop_custom/' /var/lib/tomcat7/solr/loop_custom/core.properties

# Set file permissions
sudo chown -R tomcat7:tomcat7 /var/lib/tomcat7/solr

# Restart tomcat
sudo service tomcat7 restart

# Delete all data in the copied core
curl http://localhost:8983/solr/loop_custom/update --data '<delete><query>*:*</query></delete>' -H 'Content-type:text/xml; charset=utf-8'
curl http://localhost:8983/solr/loop_custom/update --data '<commit/>' -H 'Content-type:text/xml; charset=utf-8'
```

# Reindexing all data

/admin/config/search/search_api/index/post
