@api @nrn-toolkit
Feature: ENRD NRN Toolkit.
  This Feature is aimed at creating a search page, the NRN Toolkit, to allow users searching for the basic
  website resources: internal pages, files and external pages.
  A set of specific fields are attached to existing internal contents, while a new NRN Resource content
  type is created in order to enable the inclusion of files and external links. The set of fields is
  also applied to the NRN Resource content type.

  Background: Create a bunch of NRN taxonomy terms.
    Given 'enrd_resource_type' terms:
      | name              |
      | BDD Event         |
      | BDD Article       |
      | BDD Publication   |
      | BDD Web page      |
      | BDD Good practice |
    And 'enrd_networking' terms:
      | name                     | parent           |
      | BDD NRN Operation        | Running the NRNs |
      | BDD Fostering innovation | NRN Objectives   |
      | BDD Communication        | NRN Tasks        |

  @anonymous @nrn_resource
  Scenario: As Anonymous I should see the configured NRN Resource fields (+ the general shared fields).
    Given I am an anonymous user
    # Create a node of type NRN Resource to include an External resource.
    And I am viewing an "nrn_resource" content in "published" status:
      | title                          | BDD NRN External Resource Test                  |
      | field_enrd_nrn_description     | BDD NRN External Resource Description           |
      | field_enrd_nrn_resource_type   | External link                                   |
      | field_enrd_nrn_external_link   | http://example-bdd.com - http://example-bdd.com |
      | field_enrd_nrn_include_toolkit | 1                                               |
      | field_enrd_nrn_type            | BDD Article                                     |
      | field_tax_networking           | BDD NRN Operation                               |
      | field_enrd_nrn_date            | 01-03-2018                                      |
    When I am on "nrn-resource/bdd-nrn-external-resource-test"
    Then I should see the heading "BDD NRN External Resource Test"
    And I should see the text "BDD NRN External Resource Description" in the "content" region
    And I should see the text "Type: BDD Article" in the "content" region
    And I should see the text "Date: March 2018"

  @anonymous
  Scenario: As Anonymous I should not see the NRN-specific fields of an internal page.
    Given I am an anonymous user
    # Create a node of type Event to include an internal resource.
    And I am viewing an "event" content in "published" status:
      | title                            | BDD NRN Event                   |
      | field_enrd_nrn_include_toolkit   | 1                               |
      | body                             | BDD NRN Event Description       |
      | field_enrd_nrn_type              | BDD Event                       |
      | field_tax_networking             | BDD Fostering innovation        |
      | field_enrd_nrn_date              | 01-05-2018                      |
      | field_enrd_nrn_title             | BDD NRN Alternative Event Title |
      | field_enrd_nrn_alter_description | BDD NRN Alternative Event Desc  |
    When I am on "nrn-resource/bdd-nrn-event"
    And I should not see the text "Type: BDD Event" in the "content" region
    And I should not see the text "Date: May, 2018" in the "content" region
    And I should not see the heading "BDD NRN Alternative Event Title"
    And I should not see the text "BDD NRN Alternative Event Desc" in the "content" region

  @anonymous @wip
  # This scenario is meant to test an NRN Resource to include a file resource.
  # In order to work, it should be readapted.
  Scenario: As Anonymous I should see the NRN Resource "File" media field.
    Given: I am an anonymous user
    And I am viewing an "nrn_resource" content in "published" status:
      | title                          | BDD NRN File Resource Test |
      | field_enrd_nrn_description     | BDD NRN Description        |
      | field_enrd_nrn_resource_type   | Internal file              |
      | field_enrd_nrn_include_toolkit | 1                          |
      | field_enrd_nrn_type            | BDD Article                |
      | field_tax_networking           | BDD NRN Operation          |
      | field_enrd_nrn_date            | 01-03-2018                 |

    Given I am logged in as a user with the "webmaster" role
    And I am on "nrn-resource/bdd-nrn-file-resource-test"
    And I click "New draft"
    # National NRN image.
    And I attach the file "bdd-file.pdf" to "media[field_enrd_nrn_file_und_0]"
    And I press "Save"
    Then I should see the link "bdd-file.pdf" in the "content" region

  @javascript @webmaster @nrn-settings
  Scenario Outline: Check that a user can set a value to the NRN shared fields.
    Given I am logged in as a user with the "webmaster" role

    When I am viewing a "<bundle>" content in "published" status:
      | title                            | BDD NRN Toolkit content Title |
      | language                         | en                            |
      | field_enrd_nrn_include_toolkit   | 1                             |
      | field_enrd_nrn_type              | <resource_type>               |
      | field_tax_networking             | BDD NRN Operation             |
      | field_enrd_nrn_date              | 01-05-2018                    |
      | field_enrd_nrn_title             | BDD NRN Alternative Title     |
      | field_enrd_nrn_alter_description | BDD NRN Alternative Desc      |

    When I am at "admin/content"
    Then I should see the text "BDD NRN Toolkit content Title" in the "<name>" row

    Examples:
      | bundle          | resource_type     | name                   |
      | page            | BDD Web page      | Basic page             |
      | publication_ehd | BDD Publication   | Evaluation Publication |
      | event           | BDD Event         | Event                  |
      | nrn_profile     | BDD Article       | NRN Profile            |
      | project         | BDD Good practice | Project                |
      | publication     | BDD Publication   | Publication            |

  @filters @solr @clean @javascript
  Scenario: As Anonymous user I can search for NRN content by filtering according to the
  main clusters and by using the "Type" filter and the free-text search box, the latter available on the Landing page.
    Given: I am an anonymous user
    # Create nodes of type NRN Resource to include External link resources.
    And I am viewing an "nrn_resource" content in "published" status:
      | title                          | BDD NRN Solr External Resource Test             |
      | language                       | en                                              |
      | field_enrd_nrn_description     | BDD NRN Solr External Resource Description      |
      | field_enrd_nrn_resource_type   | External link                                   |
      | field_enrd_nrn_external_link   | http://example-bdd.com - http://example-bdd.com |
      | field_enrd_nrn_include_toolkit | 1                                               |
      | field_enrd_nrn_type            | BDD Article                                     |
      | field_tax_networking           | BDD NRN Operation                               |
      | field_enrd_nrn_date            | 01-03-2018                                      |
    And I am viewing an "nrn_resource" content in "published" status:
      | title                          | BDD Solr Second NRN External Resource               |
      | language                       | en                                                  |
      | field_enrd_nrn_description     | BDD Solr Second NRN External Res Description        |
      | field_enrd_nrn_resource_type   | External link                                       |
      | field_enrd_nrn_external_link   | http://example-2-bdd.com - http://example-2-bdd.com |
      | field_enrd_nrn_include_toolkit | 1                                                   |
      | field_enrd_nrn_type            | BDD Web page                                        |
      | field_tax_networking           | BDD Fostering innovation                            |
      | field_enrd_nrn_date            | 01-05-2018                                          |
    # Create a node of type Publication to include an internal resource and show the default title + desc.
    And I am viewing a "publication" content in "published" status:
      | title                          | BDD Solr NRN Publication             |
      | language                       | en                                   |
      | field_enrd_publication_desc    | BDD Solr NRN Publication Description |
      | field_enrd_nrn_include_toolkit | 1                                    |
      | field_enrd_nrn_type            | BDD Publication                      |
      | field_tax_networking           | BDD Fostering innovation             |
      | field_enrd_nrn_date            | 01-05-2018                           |
    # Create a node of type Publication to include an internal resource and show the custom title + desc.
    And I am viewing a "publication" content in "published" status:
      | title                            | BDD Solr Test Publication             |
      | language                         | en                                    |
      | field_enrd_publication_desc      | BDD Solr Test Publication Description |
      | field_enrd_nrn_include_toolkit   | 1                                     |
      | field_enrd_nrn_type              | BDD Publication                       |
      | field_tax_networking             | BDD NRN Operation                     |
      | field_enrd_nrn_date              | 01-05-2018                            |
      | field_enrd_nrn_title             | BDD Test Publ Title                   |
      | field_enrd_nrn_alter_description | BDD Test Publ Description             |
    # Create a node of type NRN Profile as an internal resource.
    And I am viewing an "nrn_profile" content in "published" status:
      | title                          | BDD Solr Test NRN Profile             |
      | language                       | en                                    |
      | field_enrd_nrnp_brief_intro    | BDD Solr Test NRN Profile Description |
      | field_enrd_nrn_include_toolkit | 1                                     |
      | field_enrd_nrn_type            | BDD Article                           |
      | field_tax_networking           | BDD Communication                     |
      | field_enrd_nrn_date            | 01-05-2019                            |

    When I send site contents to the Solr search index
    And I go to "networking/nrn-toolkit"

    # Main clusters filters.
    When I hover over the element "div.running-the-nrns"
    And I should see the link "BDD NRN Operation"
    And I click "BDD NRN Operation" in the "content" region

    Then I should see the text "Running the NRNs" in the "content" region
    And I should see the text "BDD NRN Operation" in the "content" region

    Then I should see the heading "BDD NRN Solr External Resource Test" in the "content" region
    And I should see the text "BDD NRN Solr External Resource Description" in the "content" region
    And I should see the text "Type: BDD Article" in the "content" region
    And I should see the text "Date:  March 2018" in the "content" region
    But I should not see the heading "BDD Solr NRN Publication"

    # When the custom title and description are set, they should be visible instead of the default ones.
    And I should see the heading "BDD Test Publ Title" in the "content" region
    But I should not see the heading "BDD Solr Test Publication"
    And I should see the text "BDD Test Publ Description" in the "content" region
    But I should not see the text "BDD Solr Test Publication Description"

    # "Type" Solr facet filter.
    Then I go to "networking/nrn-toolkit"
    When I hover over the element "div.nrn-objectives"
    And I click "BDD Fostering innovation" in the "content" region

    And I follow "BDD Publication" in the "right sidebar" region
    Then I should see the heading "BDD Solr NRN Publication" in the "content" region
    And I should not see the heading "BDD Test Publ Title"
    But I should not see the heading "BDD NRN Solr External Resource Test"
    But I should not see the heading "BDD Solr Second NRN External Resource"

    # NRN Profile bundle should be included.
    When I go to "networking/nrn-toolkit"
    And I hover over the element "div.nrn-tasks"
    And I click "BDD Communication" in the "content" region

    And I follow "BDD Article" in the "right sidebar" region
    Then I should see the heading "BDD Solr Test NRN Profile" in the "content" region

    # Free-text query.
    When I go to "networking/nrn-toolkit"
    And I fill in "keys" with "External"
    And I press the "Search" button
    # Check that the Main cluster's heading is not visible.
    Then I should not see the text "Running the NRNs" in the "content" region
    And I should not see the text "BDD NRN Operation" in the "content" region

    Then I should see the heading "BDD NRN Solr External Resource Test" in the "content" region
    And I should see the heading "BDD Solr Second NRN External Resource" in the "content" region
    But I should not see the heading "BDD Solr NRN Publication"

  @authenticated @javascript @contact-form @solr @privacy @emails @clean
  Scenario: As Authenticated I want to contact the Networking team by sending a message via the "Contact us" contact form.
    Given I am logged in as a user with the "authenticated" role
    And I am viewing an "event" content in "published" status:
      | title                          | BDD Test Contact us form       |
      | language                       | en                             |
      | field_enrd_nrn_include_toolkit | 1                              |
      | field_enrd_nrn_type            | BDD Article                    |
      | body                           | BDD NRN Contact us Description |
      | field_tax_networking           | BDD Fostering innovation       |
      | field_enrd_nrn_date            | 01-03-2018                     |

    Then I send site contents to the Solr search index
    When I go to "networking/nrn-toolkit"
    And I hover over the element "div.nrn-objectives"
    And I click "BDD Fostering innovation" in the "content" region
    Then I should see the heading "Contact us *" in the "right sidebar" region
    And I fill in "Your organisation" with "BDD Organisation"
    And I fill in "Email" with "bdd-email@bdd-example.com"
    And I fill in "Message" with "Hello, this is a message from BDD Organisation!"
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And the test email system is enabled
    And I press "Submit" in the "right sidebar" region
    Then the email to "nrn-meeting@enrd.eu" should contain "Hello, this is a message from BDD Organisation!"
    And I should see the following success messages:
      | success messages                                                                                                                                      |
      | Thank you for your submission. Your email has been sent successfully. You will be contacted shortly by the Networking team of the ENRD Contact Point. |

  @editor @workflow @moderate-all
  Scenario: As editor I want to create a new NRN Resource as well as edit and moderate a resource not created by me.
    Given I am logged in as a user with the "editor" role

    When I click "Create content"
    Then I should see the link "NRN Resource"
    And I should be able to edit a "nrn_resource" content

    When I am viewing a "nrn_resource" content in "needs_review" status:
      | title | BDD editor NRN Resource title |
    And I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Validated" in the "BDD editor NRN Resource title" row
    Then I should see the text "Validated" in the "BDD editor NRN Resource title" row

  @contributor @workflow @moderate-all
  Scenario: As contributor I cannot either edit an nrn resource other than mine or moderate it.
    Given I am logged in as a user with the "contributor" role
    And I should not be able to edit a "nrn_resource" content

    When I am viewing a "nrn_resource" content in "draft" status:
      | title | BDD contributor NRN Resource title |
    And I go to "admin/workbench"
    And I click "Moderate All"
    Then I should see the link "BDD contributor NRN Resource title"
    When I click "Change to Needs Review"
    Then I should get a 403 HTTP response

  @webmaster
  Scenario: as webmaster I should be able to see the list of submissions issued via the contact form.
    Given I am logged in as a user with the "webmaster" role
    When I am at "admin/content/webform"
    Then I click "Contact us"
    And I click "Results"
    Then I should get a "200" HTTP response
