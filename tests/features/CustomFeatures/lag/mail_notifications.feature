@api @lag_notifications
Feature: ENRD LAG Database Notifications
  This Feature is aimed at testing LAG Database rules.
  A bunch of LAG Profiles and Cooperation Offers, in which content is handled by separate workflows and user's
  roles/permissions, are created for this purpose.

  Background: Check LAG email notifications.
    And "enrd_countries" terms:
      | name        | parent         |
      | BDD Belgium | European Union |
    Given users:
      | name               | mail                           | pass | roles                         |
      | bdd-user-webmaster | bdd-user-webmaster@example.com | test | authenticated user, webmaster |
    And users:
      | name                 | mail                         | pass | roles                        | og_user_node                                             | field_enrd_lag_country |
      | bdd-user-nat-manager | bdd-user-nat-man@example.com | test | authenticated user, LAG User | European Agricultural Fund for Rural Development (EAFRD) | BDD Belgium            |
    And I am viewing a "lag" content in "published" status:
      | title                  | BDD LAG Published                                        |
      | field_enrd_lag_code    | XYZ-001                                                  |
      | og_group_ref           | European Agricultural Fund for Rural Development (EAFRD) |
      | field_enrd_lag_country | BDD Belgium                                              |
      | author                 | bdd-user-webmaster                                       |
      | language               | und                                                      |

  # Rule: ENRD LAG Draft to Ready to be Published
  @javascript @og @lags @emails @webmasters @privacy
  Scenario: Check that when a LAG is moderated to ready_to_be_published status,
  a notification is sent to LAG Database Webmaster.
    Given users:
      | name             | mail                         | pass | roles                        | og_user_node      |
      | bdd-user-contact | bdd-user-contact@example.com | test | authenticated user, LAG User | BDD LAG Published |
    And I am viewing a "lag" content in "draft" status:
      | title                  | BDD LAG Draft                                            |
      | field_enrd_lag_code    | XYZ-002                                                  |
      | og_group_ref           | European Agricultural Fund for Rural Development (EAFRD) |
      | field_enrd_lag_country | BDD Belgium                                              |
      | author                 | bdd-user-webmaster                                       |
      | language               | und                                                      |
    And I am logged in as "bdd-user-webmaster"
    # I am in the "LAG profiles" > "Updates".
    When I am at "lag-dashboard?state=1"
    And I check the box "edit-views-bulk-operations-0"
    And I press "Ask for publishing" in the "content" region
    And I wait for the batch job to finish
    Then the email to "LAG-database-webmaster@enrd.eu" should contain "LAG profile update ready for publication online"
    # Check for success message and email notification in updates of already published lags.
    And I am logged in as "bdd-user-contact"
    And I have the "LAG Contact" role in the "BDD LAG Published" group
    And I am at "my-lags"
    And I click "view"
    And I click "Update LAG profile"
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I check the box "field_publish_legal_notice"
    And I press "Save"
    Then I should see the following success messages:
      | success messages                                                   |
      | This update has been sent to the webmaster for publication online. |
      | Your changes for LAG BDD LAG Published have been saved.            |
    And the email to "LAG-database-webmaster@enrd.eu" should contain "LAG profile update ready for publication online"

  # Ready to be Published/Draft
  @javascript @og @lags @emails @author @privacy
  Scenario: Check that when ready_to_be_published/draft transition occurs,
  a notification is sent to latest revision author.
    Given users:
      | name             | mail                         | pass | roles                        | og_user_node      |
      | bdd-user-contact | bdd-user-contact@example.com | test | authenticated user, LAG User | BDD LAG Published |
    And I am logged in as "bdd-user-contact"
    And I have the "LAG Contact" role in the "BDD LAG Published" group
    When I am at "my-lags"
    And I click "manage"
    And I click "update lag profile"
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I check the box "field_publish_legal_notice"
    And I press the "Save" button
    And I am logged in as "bdd-user-webmaster"
    When I am at "lag-dashboard"
    And I click "Pending for publication"
    And I check the box "edit-views-bulk-operations-0"
    And I press "Reject publication" in the "content" region
    And I wait for the batch job to finish
    Then the email to "bdd-user-contact@example.com" should contain "ENRD LAG Database - your LAG's profile update has been rejected by the LAG webmaster"

  # Rule: ENRD LAG Ready to be Published to Published
  # Rule: ENRD LAG Database Notify Node Authors
  @javascript @og @lags @emails @lag-contact @lag-managers @author
  Scenario: Check that when ready_to_be_published/published transition occurs, a notification is sent to LAG Contacts,
  LAG Managers, National managers & node author.
    Given I am viewing a "lag" content in "ready_to_be_published" status:
      | title                  | BDD LAG RBP                                              |
      | field_enrd_lag_code    | XYZ-004                                                  |
      | og_group_ref           | European Agricultural Fund for Rural Development (EAFRD) |
      | field_enrd_lag_country | BDD Belgium                                              |
      | author                 | bdd-user-webmaster                                       |
      | language               | und                                                      |
    And users:
      | name             | mail                         | pass | roles                        | og_user_node | field_enrd_lag_country |
      | bdd-user-contact | bdd-user-contact@example.com | test | authenticated user, LAG User | BDD LAG RBP  | BDD Belgium            |
      | bdd-user-manager | bdd-user-manager@example.com | test | authenticated user, LAG User | BDD LAG RBP  | BDD Belgium            |
    Given I am logged in as "bdd-user-contact"
    And I have the "LAG Contact" role in the "BDD LAG RBP" group
    And I am logged in as "bdd-user-manager"
    And I have the "LAG Manager" role in the "BDD LAG RBP" group
    And I am logged in as "bdd-user-nat-manager"
    And I have the "National manager" role in the "European Agricultural Fund for Rural Development (EAFRD)" group
    And I am logged in as "bdd-user-webmaster"
    And I am at "lag-dashboard"
    And I click "Pending for publication"
    And I check the box "edit-views-bulk-operations-0"
    And I press "Publish" in the "content" region
    And I wait for the batch job to finish
    Then the email to "bdd-user-contact@example.com" should contain "ENRD LAG Database - your LAG's profile update is now published online"
    Then the email to "bdd-user-manager@example.com" should contain "ENRD LAG Database - your LAG's profile update is now published online"
    Then the email to "bdd-user-webmaster@example.com" should contain "ENRD LAG Database - your LAG is now published online"

  # Rule: ENRD LAG Published to Archived
  @javascript @og @lags @emails @archive
  Scenario: Check that the published -> archived transition occurs correctly.
  (Notifications TBD).
    Given I am logged in as "bdd-user-webmaster"
    When I am at "lag-dashboard"
    And I check the box "edit-views-bulk-operations-0"
    And I press "Archive" in the "content" region
    And I wait for the batch job to finish
    And I should not see the link "BDD LAG Published"
    # I am in the "LAG profiles" > "Archived" section.
    When I am at "lag-dashboard?state=3"
    And I wait for AJAX to finish
    Then I should see the link "BDD LAG Published"

  # Rule: ENRD LAG Archived to Draft
  @javascript @og @lags @emails @lag-contacts @lag-managers
  Scenario: Check that when archived -> draft transition occurs, a notification is sent to LAG Contacts and LAG Managers.
    Given I am viewing a "lag" content in "archived" status:
      | title                  | BDD LAG Archived                                         |
      | og_group_ref           | European Agricultural Fund for Rural Development (EAFRD) |
      | field_enrd_lag_country | BDD Belgium                                              |
      | author                 | bdd-user-webmaster                                       |
      | language               | und                                                      |
    And users:
      | name             | mail                         | pass | roles                        | og_user_node     |
      | bdd-user-contact | bdd-user-contact@example.com | test | authenticated user, LAG User | BDD LAG Archived |
      | bdd-user-manager | bdd-user-manager@example.com | test | authenticated user, LAG User | BDD LAG Archived |
    Given I am logged in as "bdd-user-contact"
    And I have the "LAG Contact" role in the "BDD LAG Archived" group
    Given I am logged in as "bdd-user-manager"
    And I have the "LAG Manager" role in the "BDD LAG Archived" group
    And I am logged in as "bdd-user-webmaster"
    # I am in the "LAG profiles" > "Archived" section.
    When I am at "lag-dashboard?state=3"
    And I wait for AJAX to finish
    And I check the box "edit-views-bulk-operations-0"
    And I press "Create new Draft" in the "content" region
    And I wait for the batch job to finish
    Then the email to "bdd-user-contact@example.com" should contain "ENRD LAG Database - your archived LAG has been updated"
    Then the email to "bdd-user-manager@example.com" should contain "ENRD LAG Database - your archived LAG has been updated"

  # Check Cooperation Offer email notifications
  @og @coop @emails @webmasters @privacy
  # Draft/Ready to be Published
  Scenario: Check that when a cooperation offer is moderated to ready_to_be_published status,
  a notification is sent to the LAG Database Webmaster.
    Given "enrd_project_types" terms:
      | name             |
      | BDD Procjet type |
    And "enrd_key_themes_of_strategy" terms:
      | name      |
      | BDD Topic |
    And I am viewing a "cooperation_offer" content in "draft" status:
      | title                           | BDD COOP DRAFT     |
      | field_enrd_coop_partner_country | BDD Belgium        |
      | field_enrd_coop_expiry_date     | 31-12-2019 09:00   |
      | og_lag_group_ref                | BDD LAG Published  |
      | author                          | bdd-user-webmaster |
      | language                        | und                |
    And I am viewing a "cooperation_offer" content in "published" status:
      | title                                | BDD COOP PUBLISHED         |
      | field_enrd_coop_type                 | BDD Procjet type           |
      | field_enrd_coop_topic_of_project     | BDD Topic                  |
      | field_enrd_coop_context:value        | BDD Context                |
      | field_enrd_coop_context:format       | plain_text                 |
      | field_enrd_coop_brief_summary:value  | BDD Project summary        |
      | field_enrd_coop_brief_summary:format | plain_text                 |
      | field_enrd_coop_objectives:value     | BDD Objectives             |
      | field_enrd_coop_objectives:format    | plain_text                 |
      | field_enrd_coop_lag_email:email      | coop_published@example.com |
      | field_enrd_coop_partner_country      | BDD Belgium                |
      | field_enrd_coop_expiry_date          | 31-12-2019 09:00           |
      | og_lag_group_ref                     | BDD LAG Published          |
      | author                               | bdd-user-webmaster         |
      | language                             | und                        |
    And users:
      | name             | mail                         | pass | roles                        | og_user_node      |
      | bdd-user-contact | bdd-user-contact@example.com | test | authenticated user, LAG User | BDD LAG Published |
    And I am logged in as "bdd-user-contact"
    And I have the "LAG Contact" role in the "BDD LAG Published" group
    When I am at "my-lags"
    And I click "manage"
    And I click "Cooperation offers"
    And I check the box "edit-views-bulk-operations-0"
    And I press "Ask for publication" in the "content" region
    Then I should see the following success messages:
      | success messages                                                   |
      | This update has been sent to the webmaster for publication online. |
    And I should see "Cooperation offers pending for publication"
    But I should not see the link "Ask for publication"
    Then the email to "LAG-database-webmaster@enrd.eu" should contain "ENRD LAG Database - Cooperation Offer update ready for publication online"
    # Check for success message and email notification in updates of already published cooperation offers.
    When I am at "my-lags"
    And I click "manage"
    And I click "Cooperation offers"
    And I click "view" in the "BDD COOP PUBLISHED" row
    And I click "Update offer"
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I check the box "field_publish_legal_notice"
    And I press "Save"
    Then I should see the following success messages:
      | success messages                                                       |
      | This update has been sent to the webmaster for publication online.     |
      | Your changes for Cooperation Offer BDD COOP PUBLISHED have been saved. |
    And the email to "LAG-database-webmaster@enrd.eu" should contain "ENRD LAG Database - Cooperation Offer update ready for publication online"

  # Ready to be Published to Draft
  @og @coop @emails @author @privacy
  Scenario: Check that when ready_to_be_published/draft transition occurs,
  a notification is sent to latest revision author.
    Given users:
      | name             | mail                         | pass | roles                        | og_user_node      |
      | bdd-user-contact | bdd-user-contact@example.com | test | authenticated user, LAG User | BDD LAG Published |
    And "enrd_project_types" terms:
      | name             |
      | BDD Procjet type |
    And "enrd_key_themes_of_strategy" terms:
      | name      |
      | BDD Topic |
    And I am viewing a "cooperation_offer" content in "published" status:
      | title                                | BDD COOP TO REPUBLISH         |
      | field_enrd_coop_type                 | BDD Procjet type              |
      | field_enrd_coop_topic_of_project     | BDD Topic                     |
      | field_enrd_coop_context:value        | BDD Context                   |
      | field_enrd_coop_context:format       | plain_text                    |
      | field_enrd_coop_brief_summary:value  | BDD Project summary           |
      | field_enrd_coop_brief_summary:format | plain_text                    |
      | field_enrd_coop_objectives:value     | BDD Objectives                |
      | field_enrd_coop_objectives:format    | plain_text                    |
      | field_enrd_coop_lag_email:email      | coop_to_republish@example.com |
      | field_enrd_coop_partner_country      | BDD Belgium                   |
      | field_enrd_coop_expiry_date          | 31-12-2022 09:00              |
      | og_lag_group_ref                     | BDD LAG Published             |
      | author                               | bdd-user-webmaster            |
      | language                             | und                           |
    And I am logged in as "bdd-user-contact"
    And I have the "LAG Contact" role in the "BDD LAG Published" group
    When I am at "my-lags"
    And I click "manage"
    And I click "Cooperation offers"
    And I click "edit"
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I check the box "field_publish_legal_notice"
    And I press the "Save" button
    And I am logged in as "bdd-user-webmaster"
    When I am at "lag-dashboard"
    And I click "Cooperation offers"
    And I click "Pending for publication"
    And I click "BDD COOP TO REPUBLISH"
    And I select "draft" from "state"
    And I press "Apply"
    Then the email to "bdd-user-contact@example.com" should contain "ENRD LAG Database - your LAG's Cooperation Offer has been rejected by the LAG webmaster"
    # I am in the "Coop. offers" > "Active" > "Updates" section.
    When I am at "lag-dashboard/cooperation-offers?state=3"
    Then I should see the link "BDD COOP TO REPUBLISH"

  @javascript @og @coop @emails @lag-contacts @lag-managers @author
  # Ready be Published to Published
  # Notify Cooperation Offers Node Authors
  Scenario: Check that when ready_to_be_published/published transition occurs,
  a notification is sent to LAG Contacts and LAG Managers and node author.
    Given users:
      | name             | mail                         | pass | roles                        | og_user_node | field_enrd_lag_country |
      | bdd-user-contact | bdd-user-contact@example.com | test | authenticated user, LAG User | BDD LAG RBP  | BDD Belgium            |
      | bdd-user-manager | bdd-user-manager@example.com | test | authenticated user, LAG User | BDD LAG RBP  | BDD Belgium            |
    And I am viewing a "cooperation_offer" content in "ready_to_be_published" status:
      | title                           | BDD COOP RBP       |
      | field_enrd_coop_partner_country | BDD Belgium        |
      | field_enrd_coop_expiry_date     | 31-12-2022 09:00   |
      | og_lag_group_ref                | BDD LAG Published  |
      | author                          | bdd-user-webmaster |
      | language                        | und                |
    And I am logged in as "bdd-user-contact"
    And I have the "LAG Contact" role in the "BDD LAG Published" group
    And I am logged in as "bdd-user-manager"
    And I have the "LAG Manager" role in the "BDD LAG Published" group
    And I am logged in as "bdd-user-webmaster"
    When I am at "lag-dashboard"
    # I am in the "Coop. offers" > "Pending for publication" section.
    When I am at "lag-dashboard/cooperation-offers/pending"
    And I check the box "edit-views-bulk-operations-0"
    And I press "Publish" in the "content" region
    And I wait for the batch job to finish
    Then the email to "bdd-user-contact@example.com" should contain "ENRD LAG Database - your LAG's Cooperation Offer is now published online"
    Then the email to "bdd-user-manager@example.com" should contain "ENRD LAG Database - your LAG's Cooperation Offer is now published online"
    Then the email to "bdd-user-webmaster@example.com" should contain "ENRD LAG Database - your Cooperation offer is now published online"
    And I should not see the link "BDD COOP RBP"
    # I am in the "Coop. offers" > "Active" section.
    When I am at "lag-dashboard/cooperation-offers"
    Then I should see the link "BDD COOP RBP"

  @scheduling
  Scenario: Schedule ESI Funds OG and related LAGs for periodic notifications
  once nodes of these content types are created.
    Given "enrd_esi_funds" terms:
      | name |
      | BDD  |
    And I am viewing a "esi_funds_og" content in "published" status:
      | title                    | BDD Scheduled FUND |
      | field_enrd_main_esi_fund | BDD                |
      | language                 | und                |
    And I am viewing a "lag" content in "published" status:
      | title                  | BDD LAG Published  |
      | field_enrd_lag_code    | XYZ-999            |
      | og_group_ref           | BDD Scheduled FUND |
      | field_enrd_lag_country | BDD Belgium        |
      | author                 | bdd-user-webmaster |
      | language               | und                |
    # LAG Managers solicit scheduling.
    And I am logged in as a user with the "webmaster" role
    When I am at "admin/config/workflow/rules/schedule"
    Then I should see "XYZ-999-lag-notification"
