@api @lag
Feature: ENRD LAG Database.
  This Feature aims to create LAG Profiles and Cooperation Offers,
  in which content is handled by separate workflows and user's
  roles/permissions.

  Background: Create a bunch of users and nodes to test different workflows inside groups.
    Given 'enrd_countries' terms:
      | name              | parent         |
      | BDD Belgium       | European Union |
      | BDD Italy         | European Union |
      | BDD France        | European Union |
      | BDD France Region | BDD France     |
    And 'enrd_esif_programme' terms:
      | name             | parent      |
      | BDD Belgium      | EAFRD       |
      | BDD Italy        | ESF         |
      | BDD France       | ESF         |
      | BDD Programme BE | BDD Belgium |
      | BDD Programme IT | BDD Italy   |
      | BDD Programme FR | BDD France  |
    And I am viewing a "lag" content in "draft" status:
      | title                     | BDD LAG Draft                                            |
      | field_enrd_lag_country    | BDD Belgium                                              |
      | field_enrd_esif_programme | BDD Programme BE                                         |
      | field_enrd_lag_code       | BDD-BE-LAG-DRA                                           |
      | og_group_ref              | European Agricultural Fund for Rural Development (EAFRD) |
      # Avoid token notice if node log is empty until issue is solved:
      # See: https://www.drupal.org/project/token/issues/1546182
      | log                       | A LAG in draft status                                    |
      | language                  | und                                                      |
    And I am viewing a "lag" content in "ready_to_be_published" status:
      | title                     | BDD LAG RBP                                              |
      | field_enrd_lag_country    | BDD Belgium                                              |
      | field_enrd_esif_programme | BDD Programme BE                                         |
      | field_enrd_lag_code       | BDD-BE-LAG-RBP                                           |
      | og_group_ref              | European Agricultural Fund for Rural Development (EAFRD) |
      | language                  | und                                                      |
    And I am viewing a "lag" content in "ready_to_be_published" status:
      | title                     | BDD LAG RBP 2                                            |
      | field_enrd_lag_country    | BDD Belgium                                              |
      | field_enrd_esif_programme | BDD Programme BE                                         |
      | field_enrd_lag_code       | BDD-BE-LAG-RBP2                                          |
      | og_group_ref              | European Agricultural Fund for Rural Development (EAFRD) |
      | language                  | und                                                      |
    And I am viewing a "lag" content in "published" status:
      | title                     | BDD LAG Published                                        |
      | field_enrd_lag_country    | BDD Belgium                                              |
      | field_enrd_esif_programme | BDD Programme BE                                         |
      | field_enrd_lag_code       | BDD-BE-LAG-PUB                                           |
      | og_group_ref              | European Agricultural Fund for Rural Development (EAFRD) |
      | language                  | und                                                      |
    And I am viewing a "lag" content in "archived" status:
      | title                     | BDD LAG ARC                                              |
      | field_enrd_lag_country    | BDD Belgium                                              |
      | field_enrd_esif_programme | BDD Programme BE                                         |
      | field_enrd_lag_code       | BDD-BE-LAG-ARC                                           |
      | og_group_ref              | European Agricultural Fund for Rural Development (EAFRD) |
      | language                  | und                                                      |
    And I am viewing a "cooperation_offer" content in "published" status:
      | title                           | BDD COOP          |
      | field_enrd_coop_partner_country | BDD Belgium       |
      | field_enrd_coop_expiry_date     | 31-12-2019 09:00  |
      | og_lag_group_ref                | BDD LAG Published |
      | language                        | und               |

  @anonymous @solr @clean
  Scenario: As anonymous user, I can search for published LAGs.
    Given I am an anonymous user
    When I am at "/leader-clld/lag-database"
    Then I should get a "200" HTTP response
    And I should not see the following error messages:
      | error messages                                                                                     |
      | Search is temporarily unavailable. If the problem persists, please contact the site administrator. |

  @required @fields
  Scenario: Check for required (basic, contact info) fields when creating LAGs.
    Given I am logged in as a user with the "LAG User" roles and I have the following fields:
      | mail                   | bdd-user-nat-manager@example.com |
      | field_enrd_lag_country | BDD Belgium                      |
    And I have the "National manager" role in the "European Agricultural Fund for Rural Development (EAFRD)" group
    When I am at "node/add/lag"
    Then I should not see "Text format" in the ".filter-wrapper" element
    And I should see "LAG contact info" in the "content" region
    And I should see "Additional LAG info" in the "content" region
    And I should see "LAG funding" in the "content" region
    And I should see "Cooperation details" in the "content" region
    And I should see "LAG projects and documents" in the "content" region

    And I should see "Would you like to share additional documents related to your LAG?" in the ".field-name-field-enrd-lag-documentation" element
    And I should see "You are invited to upload documents such as your LAG's Local Development Strategy, information and communication materials." in the ".field-name-field-enrd-lag-documentation" element

    When I press the "Save" button
    Then I should see the following error message:
      | error messages                                    |
      | LAG code field is required.                       |
      | LAG email field is required.                      |
      | Address 1 field is required.                      |
      | City field is required.                           |
      | LAG name field is required.                       |
      | LAG manager email field is required.              |
      | LAG manager (Name and Surname) field is required. |

    Given I am logged in as a user with the "webmaster, LAG User" roles
    When I am at "node/add/cooperation-offer"
    # Check if third level terms options in Country(ies) select are hidden.
    Then I should not have the following options for "Country(ies)":
      | options              |
      | ---BDD France Region |
    When I press the "Save" button
    Then I should see the following error message:
      | error messages                          |
      | Project idea summary field is required. |
      | Context field is required.              |
      | LAG email field is required.            |
      | Objectives field is required.           |
      | Project topic field is required.        |
      | Project type field is required.         |
      | Country field is required.              |
      | Offer name field is required.           |
      | Offering LAG field is required.         |

  @javascript @published @lags @anonymous
  Scenario: Create a LAG node and check how it displays info in the frontend.
    Given I am an anonymous user
    And I am viewing a "lag" content in "published" status:
      | field_enrd_lag_code                | BDD-BE-01                                                |
      | title                              | BDD LAG 01                                               |
      | og_group_ref                       | European Agricultural Fund for Rural Development (EAFRD) |
      | field_enrd_lag_country             | BDD Belgium                                              |
      | field_enrd_lag_geo_coverage        | Bruxelles                                                |
      | field_enrd_lag_spoken_languages    | French                                                   |
      | field_enrd_lag_email:email         | bdd_office@example.com                                   |
      | field_enrd_lag_manager_name        | John Doe                                                 |
      | field_enrd_lag_manager_email:email | john_doe@example.com                                     |
      | field_enrd_lag_key_themes          | Innovation                                               |
      | field_enrd_lag_phys_demographic    | Inland                                                   |
      | field_enrd_lag_assets_land_use     | Industry                                                 |
      | field_enrd_lag_size_territory      | 500000                                                   |
      | field_enrd_lag_inhabitants         | 120000                                                   |
      | field_enrd_lag_entities_num        | 50                                                       |
      | field_enrd_lag_staff_num           | 20                                                       |
      | field_enrd_lag_total_budget        | 5000000                                                  |
      | field_enrd_lag_eafrd_contrib       | 1000000                                                  |
      | field_enrd_lag_esf_contrib         | 1000000                                                  |
      | field_enrd_lag_erdf_contrib        | 1000000                                                  |
      | field_enrd_lag_emff_contrib        | 1000000                                                  |
      | field_enrd_lag_national_contrib    | 500000                                                   |
      | field_enrd_lag_private_contrib     | 500000                                                   |
      | field_enrd_lag_interested_in       | Looking for a partner                                    |
      | field_enrd_lag_themes_interests    | Innovation                                               |
      | field_enrd_lag_phone               | 123456789                                                |
      | field_enrd_lag_clld_name           | Jane Doe                                                 |
      | field_enrd_lag_clld_email:email    | jane_doe@example.com                                     |
      | language                           | und                                                      |
    Then I should see the heading "BDD LAG 01"
    And I should see "LAG code: BDD-BE-01"
    And I should see "Main ESI Fund: European Agricultural Fund for Rural Development (EAFRD)"
    And I should see "Contact information"
    And I should see "Spoken languages: French"
    And I should see "Phone: +12 345 6789"
    And I should see "LAG email:"
    And I should see the link "bdd_office@example.com"
    And I should see "LAG manager: John Doe"
    And I should see "LAG Manager email:"
    And I should see the link "john_doe@example.com"

    # Additional Information
    And I should see "Additional information" in the "content" region
    And I click "Additional information"
    And I wait
    And I should see "Key themes of LAG strategy: Innovation"
    And I should see "Physical & demographic characteristics of LAG area: Inland"
    And I should see "Assets & land use of the LAG area: Industry"
    And I should see "Size of territory (km²): 500000"
    And I should see "No. of inhabitants: 120000"
    And I should see "Municipalities covered: Bruxelles"
    And I should see "Number of entities in LAG decision body: 50"
    And I should see "Number of LAG staff: 20"

    # LAG Funding
    And I should see "LAG Funding" in the "content" region
    And I click "LAG Funding"
    And I should see "Total LAG budget: € 5 000 000"
    But I should not see "Total LAG budget: € 5000000"
    And I should see "EAFRD contribution: € 1 000 000"
    But I should not see "EAFRD contribution: € 1000000"
    And I should see "ESF contribution: € 1 000 000"
    But I should not see "ESF contribution: € 1000000"
    And I should see "ERDF contribution: € 1 000 000"
    But I should not see "ERDF contribution: € 1000000"
    And I should see "EMFF contribution: € 1 000 000"
    But I should not see "EMFF contribution: € 1000000"
    And I should see "National contribution: € 500 000"
    But I should not see "National contribution: € 500000"
    And I should see "Private contribution: € 500 000"
    But I should not see "Private contribution: € 500000"

    # Cooperation details
    And I should see "Cooperation details" in the "right sidebar" region
    And I should see "Looking for a Cooperation partner?: Yes"
    And I should see "Themes of interest for cooperation activities: Innovation"
    And I should see "Jane Doe" in the "right sidebar" region
    And I should see the "a" element with the "href" attribute set to "mailto:jane_doe@example.com" in the "right sidebar" region

  @javascript @lags @phone
  Scenario: View a basic LAG with a wrong phone number format and check if the warning message is displayed.
    Given I am logged in as a user with the "webmaster, LAG User" roles
    And I am viewing a "lag" content in "published" status:
      | field_enrd_lag_code    | BDD-BE-02                                                |
      | title                  | BDD LAG 02                                               |
      | og_group_ref           | European Agricultural Fund for Rural Development (EAFRD) |
      | field_enrd_lag_country | BDD Belgium                                              |
      | field_enrd_lag_phone   | 00000000000000                                           |
      | language               | und                                                      |
    And I click "Update LAG profile"
    Then I should see an "input.lag-phone-number-warning" element
    And I should see an "span.lag-phone-number-warning-message" element
    And I should see the text "Please review and update your phone number in line with the following format: +12 345 6789."

  @published @coop
  Scenario: Create a Cooperation Offer node and check how it displays info in the frontend.
    Given I am an anonymous user
    And I am viewing a "cooperation_offer" content in "published" status:
      | og_lag_group_ref                 | BDD LAG Published                             |
      | field_enrd_coop_lang_lag_staff   | French                                        |
      | title                            | BDD Coop Offer                                |
      | field_enrd_coop_type             | Cooperation within the country                |
      | field_enrd_coop_topic_of_project | Innovation                                    |
      | field-enrd-coop-context          | Research and innovation in Europe             |
      | field-enrd-coop-brief-summary    | Integer volutpat sem a lectus commodo         |
      | field-enrd-coop-objectives       | Aliquam non ipsum a augue condimentum maximus |
      | field-enrd-coop-expiry-date      | 31-12-2017 09:00                              |
      | field_enrd_coop_partner_country  | Belgium                                       |
      | field-enrd-coop-partner-region   | BE-Flanders                                   |
      | field_enrd_coop_key_themes       | Innovation                                    |
      | field_enrd_coop_physical_demog   | Inland                                        |
      | field_enrd_coop_assets_area      | Industry                                      |
      | field_enrd_coop_sea_basins       | North Sea                                     |
      | language                         | und                                           |

    Then I should see "Cooperation Offer"
    And I should see "Offer name: BDD Coop Offer"
    And I should see "Offering LAG:"
    And I should see the link "BDD LAG Published"
    And I should see "Country: BDD Belgium"

    And I should see "Looking to cooperate with" in the "content" region
    And I should see "Country(ies): Belgium"
    And I should see "Assets of the area: Industry"

    And I should see "Project idea" in the "content" region
    And I should see "Project type: Cooperation within the country"
    And I should see "Project topic: Innovation"

    And I should see "Contact this LAG *" in the "right sidebar" region
    And I should see "Your organisation *" in the "right sidebar" region
    And I should see "Message *" in the "right sidebar" region
    And I should see "Your email *" in the "right sidebar" region

  @feeds
  Scenario: Check that feeds importer is correctly set up.
    # Check that feeds mapping and tampers exist.
    Given I am logged in as a user with the "webmaster" role
    When I am at "admin/structure/feeds/enrd_lag_database"
    Then I should get a "200" HTTP response
    When I am at "admin/structure/feeds/enrd_lag_database/tamper"
    Then I should get a "200" HTTP response
    And I should not see "Overridden"
    # Check the import page.
    When I am at "import/enrd_lag_database"
    Then I should get a "200" HTTP response

  @feeds @feeds-importer @javascript @wip
  # May fail because warning: Creating default object from empty value in _enrd_feeds_taxonomy_hierarchy_set_caches().
  Scenario: As a webmaster, I want to import some basic data (LAG contact info) into LAGs,
  to give users the possibility to edit them and add detailed info.
    Given I am logged in as a user with the "webmaster" role
    When I am at "import/enrd_lag_database"
    And I attach the file "BDD_LAG_data-import-export_template.csv" to "File"
    And I press "Import"
    And I wait for the batch job to finish
    Then I should see the success message "Created 1 content."

  @og @og-settings
  Scenario: Check that OG permissions config pages exists for LAGs and Funds.
    Given I am logged in as a user with the "webmaster" role
    When I am at "admin/config/group/permissions/node/lag"
    Then I should get a "200" HTTP response
    When I am at "admin/config/group/permissions/node/esi_funds_og"
    Then I should get a "200" HTTP response

  @og @og-roles
  Scenario: Check that OG roles have been added to LAG and ESI Funds groups.
    # LAGs
    Given I am logged in as a user with the "webmaster" role
    When I am at "admin/config/group/roles/node/lag"
    Then I should get a "200" HTTP response
    And I should see the text "LAG Contact"
    And I should see the text "LAG Manager"
    When I am at "admin/config/group/roles/node/esi_funds_og"
    Then I should get a "200" HTTP response
    And I should see the text "National manager"

  # Webmaster
  @og @webmasters @workflow @lags
  Scenario: Check Webmaster moderation tasks:
    Given I am logged in as a user with the "webmaster, LAG User" roles
    # From Draft state
    And I am at "lag/bdd-be-lag-dra"
    When I click "Moderate"
    Then I should have the following options for "edit-state":
      | option                |
      | Ready to be published |
      | Published             |
      | Archived              |
    And I should not see the text "and all its validated translations"
    When I select "ready_to_be_published" from "edit-state"
    And I press the "Apply" button
    Then I should see "The current state is Ready to be published."

    # From Ready to be published state
    When I am at "lag/bdd-be-lag-rbp"
    And I click "Moderate"
    Then I should have the following options for "edit-state":
      | option    |
      | Draft     |
      | Published |
      | Archived  |
    And I should not see the text "and all its validated translations"
    When I select "published" from "edit-state"
    And I press the "Apply" button
    Then I should see "This is the published revision."
    When I am at "lag/bdd-be-lag-rbp2"
    And I click "Moderate"
    But I should have the following options for "edit-state":
      | option    |
      | Draft     |
      | Published |
      | Archived  |
    When I select "draft" from "edit-state"
    And I press the "Apply" button
    Then I should see "The current state is Draft."
    And I should not see the text "and all its validated translations"

    # From Archived state
    When I am at "lag/bdd-be-lag-arc"
    And I click "Moderate"
    Then I should have the following options for "edit-state":
      | option                |
      | Draft                 |
      | Ready to be published |
      | Published             |
    And I should not see the text "and all its validated translations"
    When I select "draft" from "edit-state"
    And I press the "Apply" button
    Then I should see "The current state is Draft."

    # From Published state
    When I am at "lag/bdd-be-lag-pub"
    And I click "Unpublish"
    Then I should have the following options for "edit-state":
      | option                |
      | Draft                 |
      | Ready to be published |
      | Archived              |
    When I select "archived" from "edit-state"
    And I press the "Unpublish" button
    Then I should see "The current state is Archived."
    And I should not see the text "and all its validated translations"

  @og @webmaster @workflow @lags @ask-publishing
  Scenario: Check that webmasters do not see the single button "Ask for publishing".
    Given I am logged in as a user with the "webmaster, LAG User" roles
    And I am at "lag/bdd-be-lag-dra"
    Then I should not see "Ask for publishing"
    When I am at "lag/bdd-be-lag-rbp"
    Then I should not see "Ask for publishing"
    When I am at "lag/bdd-be-lag-pub"
    Then I should not see "Ask for publishing"
    When I am at "lag/bdd-be-lag-arc"
    Then I should not see "Ask for publishing"

  @og @workflow @lags @ask-publishing @privacy
  Scenario: As "LAG Manager" I ask publication through checkbox into node edit.
    Given I am logged in as a user with the "LAG User" roles
    And I have the "LAG Manager" role in the "BDD LAG Published" group
    And I am at "lag/bdd-be-lag-pub"
    Then I click "Update LAG profile"
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I check the box "field_publish_legal_notice"
    When I press "Save"
    Then I should see "This update is the most recent revision of this LAG, it has been submitted for publication and is currently under evaluation by the Webmaster. You will be able to create a new update again after the revision has been approved/rejected. If needed, you can Contact the Webmaster." in the ".workbench-info-block" element
    When I click "Currently online"
    Then I should see "A most recent updates of this LAG has been submitted for publication and is currently under evaluation by the Webmaster. You will be able to edit it again after the update has been approved/rejected. If needed, you can Contact the Webmaster." in the ".workbench-info-block" element

  @og @workflow @lags @ask-publishing @privacy
  Scenario: As "LAG Manager" I ask publication through button in the node full view.
    Given I am logged in as a user with the "LAG User" roles
    And I have the "LAG Manager" role in the "BDD LAG Published" group
    And I am at "lag/bdd-be-lag-pub"
    Then I click "Update LAG profile"
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I press "Save"
    When I press "Ask for publishing"
    Then I should see the error message containing "You must agree with the ENRD Privacy Statement to proceed."
    Then I should see the error message containing "You must agree with the Collection of Data Statement to proceed."
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I press "Ask for publishing"
    Then I should see "Ready to be published" in the ".workbench-info-block" element

  # National Manager LAGs
  @og @nsu @workflow @lags
  Scenario: Check National manager moderation tasks:
    Given I am logged in as a user with the "LAG User" roles and I have the following fields:
      | mail                   | bdd-user-nat-manager@example.com |
      | field_enrd_lag_country | BDD Belgium                      |
    And I have the "National manager" role in the "European Agricultural Fund for Rural Development (EAFRD)" group
    # Draft state
    When I am at "lag/bdd-be-lag-dra"
    Then I should see "View update"
    And I should see the link "Update LAG profile"
    When I click "Update LAG profile"
    # Ready to be Published state
    When I am at "lag/bdd-be-lag-rbp"
    Then I should see "View pending"
    But I should not see "Currently online"
    And I should not see the link "Update LAG profile"
    # Published state
    When I am at "lag/bdd-be-lag-pub"
    Then I should see "Currently online"
    And I should see the link "Update LAG profile"
    And I should see the link "BDD COOP" in the "right sidebar" region
    # Archived state
    When I am at "lag/bdd-be-lag-arc"
    Then I should see "View archived"
    And I should see the link "Update LAG profile"
    But I should not see "Currently online"
    # Check Country field access restriction
    When I am at "lag/bdd-be-lag-pub"
    And I click "Update LAG profile"
    Then I should get a "200" HTTP response
    And I should not see the text "and all its validated translations"
    When I am viewing a "lag" content in "published" status:
      | title                  | BDD LAG Italy                                            |
      | field_enrd_lag_country | BDD Italy                                                |
      | field_enrd_lag_code    | BDD-IT-PUB                                               |
      | og_group_ref           | European Agricultural Fund for Rural Development (EAFRD) |
      | language               | und                                                      |
    Then I should not see the link "Update LAG profile"

  # Check node creation permission.
  @og @webmasters
  Scenario: Check LAG Webmaster node creation permission:
    Given I am logged in as a user with the "webmaster, LAG User" roles
    When I am at "node/add"
    Then I should see the link "LAG"
    And I should see the link "Cooperation Offer"
    When I am at "node/add/lag"
    Then I should get a 200 HTTP response
    And I should not see the text "and all its validated translations"
    When I am at "node/add/cooperation-offer"
    Then I should get a 200 HTTP response
    And I should not see the text "and all its validated translations"

  @og @nsu
  Scenario: Check National manager node creation permission:
    Given I am logged in as a user with the "LAG User" roles and I have the following fields:
      | mail                   | bdd-user-nat-manager@example.com |
      | field_enrd_lag_country | BDD Belgium                      |
    And I have the "National manager" role in the "European Agricultural Fund for Rural Development (EAFRD)" group
    When I am at "node/add"
    Then I should see the link "LAG"
    And I should see the link "Cooperation Offer"
    When I am at "node/add/lag"
    Then I should get a 200 HTTP response
    And I should not see the text "and all its validated translations"
    When I am at "node/add/cooperation-offer"
    Then I should get a 200 HTTP response
    And I should not see the text "and all its validated translations"

  @anonymous @filters @solr @clean
  Scenario: As a simple user I want to refine search results
  using solr facets blocks on right sidebar, in the LAG Database Search page.
    Given I am an anonymous user
    And I am viewing a "lag" content in "published" status:
      | title                           | BDD LAG Solr BE                                          |
      | field_enrd_lag_country          | BDD Belgium                                              |
      | field_enrd_esif_programme       | BDD Programme BE                                         |
      | field_enrd_lag_code             | BDD-BE-SOLR                                              |
      | og_group_ref                    | European Agricultural Fund for Rural Development (EAFRD) |
      | field_enrd_additional_esi_funds | ESF                                                      |
      | language                        | und                                                      |
    And I am viewing a "lag" content in "published" status:
      | title                     | BDD LAG Solr IT            |
      | field_enrd_lag_country    | BDD Italy                  |
      | field_enrd_esif_programme | BDD Programme IT           |
      | field_enrd_lag_code       | BDD-IT-SOLR                |
      | og_group_ref              | European Social Fund (ESF) |
      | language                  | und                        |
    And I am viewing a "lag" content in "published" status:
      | title                     | BDD LAG Solr FR            |
      | field_enrd_lag_country    | BDD France                 |
      | field_enrd_esif_programme | BDD Programme FR           |
      | field_enrd_lag_code       | BDD-FR-SOLR                |
      | og_group_ref              | European Social Fund (ESF) |
      | language                  | und                        |
    Then I send the "lag" to the Solr search index
    And I am at "leader-clld/lag-database"
    Then I should not see "Additional Funds"
    # Filter by Country
    When I follow "BDD Belgium"
    Then I should see "BDD LAG Solr BE" in the "content" region
    And I should see "EAFRD" in the "content" region
    But I should not see "BDD LAG Solr IT" in the "content" region
    And I should not see "ESF" in the "content" region
    And I follow "Clear filters"
    # Filter by Main ESI Fund (excluding Additional Funds).
    When I follow "European Social Fund (ESF)"
    Then I should see "BDD LAG Solr IT" in the "content" region
    And I should see "BDD LAG Solr FR" in the "content" region
    And I should see "ESF" in the "content" region
    But I should not see "EAFRD" in the "content" region
    And I should not see "BDD LAG Solr BE" in the "content" region
    # Filter by ESIF Programme
    When I follow "BDD Italy"
    And I follow "BDD Programme IT"
    Then I should see "BDD LAG Solr IT" in the "content" region
    But I should not see "BDD LAG Solr BE" in the "content" region
    And I should not see "BDD LAG Solr FR" in the "content" region
    # Free-text query.
    When I fill in "keys" with "Italy"
    And I press the "Search" button
    Then I should see the link "BDD LAG Solr IT" in the "content" region
    But I should not see the link "BDD LAG Solr BE" in the "content" region
    And I should not see the link "BDD LAG Solr FR" in the "content" region

  @anonymous @filters @solr @clean
  Scenario: As Anonymous user I want to visualize the active and expired cooperation offers in different tabs
  on the CLLD Partner Search pages, even when selecting filters and running free-text search. I want to see
  a semicolon separated list of terms related to Project types.

    Given I am an anonymous user
    And 'enrd_project_types' terms:
      | name                   |
      | BDD Project type LOREM |
      | BDD Project type IPSUM |
    And I am viewing a "cooperation_offer" content in "published" status:
      | title                           | BDD Solr Active Cooperation offer              |
      | language                        | und                                            |
      | field_enrd_coop_partner_country | BDD Belgium                                    |
      | og_lag_group_ref                | BDD LAG Published                              |
      | field_enrd_coop_brief_summary   | Roses are red                                  |
      | field_enrd_coop_type            | BDD Project type LOREM, BDD Project type IPSUM |
      | field_enrd_coop_expiry_date     | today                                          |
    And I am viewing a "cooperation_offer" content in "published" status:
      | title                           | BDD Solr Expired Cooperation offer |
      | language                        | und                                |
      | field_enrd_coop_partner_country | BDD Belgium                        |
      | og_lag_group_ref                | BDD LAG Published                  |
      | field_enrd_coop_brief_summary   | Violets are blue                   |
      | field_enrd_coop_expiry_date     | 2 days ago                         |

    When I send the "cooperation_offer" to the Solr search index

    And I am at "leader-clld/clld-partner-search"
    Then I should see the link "Active offers"
    And I should see "BDD Solr Active Cooperation offer" in the "content" region
    But I should not see "BDD Solr Expired Cooperation offer" in the "content" region

    # The "Active offers" tab should be visible even when selecting a filter or running a free-text search.
    And I follow "BDD Belgium"
    Then I should see the link "Active offers"
    And I should see "BDD Solr Active Cooperation offer" in the "content" region
    But I should not see "BDD Solr Expired Cooperation offer" in the "content" region

    # Check separator for multiple terms in Cooperation offer Project type multiple value field.
    And I should see "BDD Project type LOREM; BDD Project type IPSUM"
    But I should not see "BDD Project type LOREM; BDD Project type IPSUM;"

    And I follow "Clear filters"
    When I fill in "keys" with "Roses"
    Then I should see the link "Active offers"
    And I should see "BDD Solr Active Cooperation offer" in the "content" region
    But I should not see "BDD Solr Expired Cooperation offer" in the "content" region

    When I am at "leader-clld/clld-partner-search/expired"
    Then I should see the link "Expired offers"
    And I should see "BDD Solr Expired Cooperation offer" in the "content" region
    But I should not see "BDD Solr Active Cooperation offer" in the "content" region

    # The "Expired offers" tab should be visible even when selecting a filter or running a free-text search.
    And I follow "BDD Belgium"
    Then I should see the link "Expired offers"
    And I should see "BDD Solr Expired Cooperation offer" in the "content" region
    But I should not see "BDD Solr Active Cooperation offer" in the "content" region

    And I follow "Clear filters"
    When I fill in "keys" with "Violets"
    Then I should see the link "Expired offers"
    And I should see "BDD Solr Expired Cooperation offer" in the "content" region
    But I should not see "BDD Solr Active Cooperation offer" in the "content" region
