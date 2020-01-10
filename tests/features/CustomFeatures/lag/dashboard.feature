@api @lag_dashboard
Feature: ENRD LAG Dashboard.
  This Feature aims to create LAG Profiles and Cooperation Offers,
  to test how they can be managed through custom dashboards interfaces.

  Background: Create a bunch of users and nodes to test different workflows inside groups.
    Given 'enrd_countries' terms:
      | name        | parent         |
      | BDD Italy   | European Union |
      | BDD France  | European Union |
      | BDD Belgium | European Union |
    And 'enrd_esif_programme' terms:
      | name             | parent      |
      | BDD Belgium      | EAFRD       |
      | BDD Italy        | ESF         |
      | BDD France       | ESF         |
      | BDD Programme BE | BDD Belgium |
      | BDD Programme IT | BDD Italy   |
      | BDD Programme FR | BDD France  |
    Given users:
      | name               | mail                           | pass | roles                             |
      | bdd-user-webmaster | bdd-user-webmaster@example.com | test | authenticated user, administrator |
    And I am viewing a "lag" content in "draft" status:
      | title                     | BDD LAG Draft                                            |
      | field_enrd_lag_country    | BDD Belgium                                              |
      | field_enrd_esif_programme | BDD Programme BE                                         |
      | field_enrd_lag_code       | BDD-BE-LAG-DRA                                           |
      | og_group_ref              | European Agricultural Fund for Rural Development (EAFRD) |
      | author                    | bdd-user-webmaster                                       |
      | language                  | und                                                      |
    And I am viewing a "lag" content in "ready_to_be_published" status:
      | title                     | BDD LAG RBP                                              |
      | field_enrd_lag_country    | BDD Belgium                                              |
      | field_enrd_esif_programme | BDD Programme BE                                         |
      | field_enrd_lag_code       | BDD-BE-LAG-RBP                                           |
      | og_group_ref              | European Agricultural Fund for Rural Development (EAFRD) |
      | author                    | bdd-user-webmaster                                       |
      | language                  | und                                                      |
    And I am viewing a "lag" content in "published" status:
      | title                     | BDD LAG Published                                        |
      | field_enrd_lag_country    | BDD Belgium                                              |
      | field_enrd_esif_programme | BDD Programme BE                                         |
      | field_enrd_lag_code       | BDD-BE-LAG-PUB                                           |
      | og_group_ref              | European Agricultural Fund for Rural Development (EAFRD) |
      | author                    | bdd-user-webmaster                                       |
      | language                  | und                                                      |
    And I am viewing a "lag" content in "archived" status:
      | title                     | BDD LAG ARC                                              |
      | field_enrd_lag_country    | BDD Belgium                                              |
      | field_enrd_esif_programme | BDD Programme BE                                         |
      | field_enrd_lag_code       | BDD-BE-LAG-ARC                                           |
      | og_group_ref              | European Agricultural Fund for Rural Development (EAFRD) |
      | author                    | bdd-user-webmaster                                       |
      | language                  | und                                                      |
    And users:
      | name                 | mail                             | pass | roles                        | field_enrd_lag_country | og_user_node                                             |
      | bdd-user-nat-manager | bdd-user-nat-manager@example.com | test | authenticated user, LAG User | BDD Belgium            | European Agricultural Fund for Rural Development (EAFRD) |
      | bdd-user-contact     | bdd-user-contact@example.com     | test | authenticated user, LAG User | BDD Belgium            | BDD LAG Published                                        |
      | bdd-user-manager     | bdd-user-manager@example.com     | test | authenticated user, LAG User | BDD Belgium            | BDD LAG Published                                        |
    And I am viewing a "cooperation_offer" content in "draft" status:
      | title                           | BDD COOP DRA       |
      | field_enrd_coop_partner_country | BDD Belgium        |
      | field_enrd_coop_expiry_date     | 31-12-2019 09:00   |
      | og_lag_group_ref                | BDD LAG Published  |
      | author                          | bdd-user-webmaster |
      | language                        | und                |
    And I am viewing a "cooperation_offer" content in "ready_to_be_published" status:
      | title                           | BDD COOP RBP       |
      | field_enrd_coop_partner_country | BDD Belgium        |
      | field_enrd_coop_expiry_date     | 31-12-2020 09:00   |
      | og_lag_group_ref                | BDD LAG Published  |
      | author                          | bdd-user-webmaster |
      | language                        | und                |
    And I am viewing a "cooperation_offer" content in "published" status:
      | title                           | BDD COOP           |
      | field_enrd_coop_partner_country | BDD Belgium        |
      | field_enrd_coop_expiry_date     | 31-12-2021 09:00   |
      | og_lag_group_ref                | BDD LAG Published  |
      | author                          | bdd-user-webmaster |
      | language                        | und                |
    # EXPIRED
    And I am viewing a "cooperation_offer" content in "published" status:
      | title                           | BDD COOP EXP       |
      | field_enrd_coop_partner_country | BDD Belgium        |
      | field_enrd_coop_expiry_date     | 31-12-2017 09:00   |
      | og_lag_group_ref                | BDD LAG Published  |
      | author                          | bdd-user-webmaster |
      | language                        | und                |
    And I am viewing a "cooperation_offer" content in "archived" status:
      | title                           | BDD COOP ARC       |
      | field_enrd_coop_partner_country | BDD Belgium        |
      | field_enrd_coop_expiry_date     | 31-12-2022 09:00   |
      | og_lag_group_ref                | BDD LAG Published  |
      | author                          | bdd-user-webmaster |
      | language                        | und                |

  @javascript @dashboards @emails @webmasters
  Scenario: Check dashboards functionalitites for Webmasters.
    # WEBMASTER/ADMINS
    Given I am logged in as "bdd-user-contact"
    And I have the "LAG Contact" role in the "BDD LAG Published" group
    Given I am logged in as "bdd-user-webmaster"
    When I am at "/lag-dashboard"
    And I should see the heading "LAG profiles"
    And I should see the link "Cooperation offers"
    And I should see the link "Contacts/Users"
    And I should see the link "Form submissions"
    And I should see the "#edit-actionenrd-lag-invite-action-invite-lag-manager" element with the "value" attribute set to "Resend an invite to LAG Manager" in the "content" region
    When I follow "Contacts/Users"
    Then I should see the link "LAG Contacts"
    And I should see the link "Invitee list"
    And I should see the link "NSU users"
    # Send an email.
    When I check the box "edit-views-bulk-operations-0"
    And I press "Send an email"
    Then I should see "Email subject" in the "content" region
    And I should see "Email body" in the "content" region
    And I should see the "#edit-submit" element with the "value" attribute set to "Send email" in the "content" region
    When I press "Send email"
    Then I should see the following error messages:
      | error messages                   |
      | Email subject field is required. |
      | Email body field is required.    |
    When I fill in "Email subject" with "BDD send an email test"
    When I fill in "Email body" with "BDD lorem ipsum"
    And the test email system is enabled
    And I press "Send email"
    And I press "Confirm"
    And I wait for the batch job to finish
    Then the email to "bdd-user-contact@example.com" should contain "BDD send an email test"

    When I am at "/my-lags"
    And I should see the heading "My LAGs"
    And I should see "LAG code"
    And I should see "LAG name"
    And I should see "LAG profile"
    And I should see "Manage profile & Cooperation offers"
    And I should see "BDD-BE-LAG-ARC" in the ".view-enrd-lag-dashboard-my-lags" element
    And I should see "BDD LAG ARC" in the ".view-enrd-lag-dashboard-my-lags" element
    And I should see "BDD-BE-LAG-DRA" in the ".view-enrd-lag-dashboard-my-lags" element
    And I should see "BDD LAG Draft" in the ".view-enrd-lag-dashboard-my-lags" element
    And I should see "BDD LAG Published" in the ".view-enrd-lag-dashboard-my-lags" element
    And I should see "BDD-BE-LAG-RBP" in the ".view-enrd-lag-dashboard-my-lags" element
    And I should see "BDD LAG RBP" in the ".view-enrd-lag-dashboard-my-lags" element
    And I should see the link "view"
    And I should see the link "manage"

    # FORM SUBMISSIONS
    When I am at "/lag-dashboard"
    And I click "Form submissions"
    Then I should see "LAG"
    And I should see "Total submissions"

  # NATIONAL MANAGERS
  @dashboards @nsu
  Scenario: Check dashboards functionalitites for National managers.
    Given I am logged in as "bdd-user-nat-manager"
    And I have the "National manager" role in the "European Agricultural Fund for Rural Development (EAFRD)" group
    When I am at "/lag-dashboard"
    Then I should get a "200" HTTP response
    And I should see the heading "LAG profiles"
    And I should see the link "LAG profiles"
    And I should see the link "Cooperation offers"
    And I should see the link "Contacts/Users"
    But I should not see the link "Form submissions"

    # LAG
    # Check existing links/buttons in LAG profiles tab.
    # Published
    And I should see the link "List"
    And I should see the link "Pending for publication"
    And I should see the link "Create a new LAG"
    And I should see the link "BDD LAG Published"
    And I should see the link "Export"
    And I should see "Updates"
    And I should see "Published"
    And I should see "Archived"
    # Updates
    When I follow "Updates"
    Then I should see the link "BDD LAG Draft"
    And I should see the "#edit-rules-componentrules-enrd-moderate-content-to-ready-to-be-published" element with the "value" attribute set to "Ask for publishing" in the "content" region
    And I should see the link "Export"
    # Archived
    When I follow "Archived"
    Then I should see the link "BDD LAG ARC"
    And I should see the "#edit-rules-componentrules-enrd-moderate-content-to-draft" element with the "value" attribute set to "Create new Draft" in the "content" region
    And I should see the link "Export"
    # Pending
    When I follow "Pending for publication"
    Then I should see the link "BDD LAG RBP"
    And I should not see the link "Export"

    # Check exposed filters in LAG profiles tab.
    And I should see "Search in the LAG Database"
    And I should see "Country"
    And I should see "ESI Fund"
    And I should see "ESIF Programme"
    And I should see the button "Reset"
    And I should see the button "Apply"

    # COOPERATION OFFERS
    # Check existing links/buttons in Cooperation offers tab.
    # Published
    When I click "Cooperation offers"
    Then I should see the heading "Cooperation offers"
    And I should see the link "Active"
    And I should see the link "Expired"
    And I should see the link "Pending for publication"
    And I should see the link "Export"
    # Check buttons to switch workflow state in Cooperation offers tab.
    And I should see the link "Currently online"
    And I should see the link "Archived"
    And I should see the link "Updates"
    # Check link to create a new Cooperation offer in Cooperation offers tab.
    And I should see the link "Create a new Cooperation Offer"
    # Check exposed filters in Cooperation offers tab.
    And I should see "Search in the CLLD Partner Search Tool"
    And I should see "Type of project"
    And I should see "Topic of the project"
    And I should see "ESIF Programme"
    And I should see the button "Reset"
    And I should see the button "Apply"
    # Pending
    When I follow "Pending for publication"
    Then I should see the link "BDD COOP RBP"
    And I should see the link "BDD LAG Published"
    And I should not see the link "Export"

    #CONTACTS USERS
    # Check existing links/buttons in Contacts/Users tab.
    When I click "Contacts/Users"
    Then I should see the heading "LAG Contacts"
    And I should see the link "LAG Contacts"
    And I should see the link "Invitee list"
    And I should not see the link "NSU users"
    # Check link to send an invite to user.
    And I should see the link "Invite/add a user"
    # Check exposed filters in Contacts/Users tab
    And I should see "Free search"
    And I should see "Country"
    And I should not see "ESI Fund"
    And I should see "LAG Role"
    And I should see the button "Reset"
    And I should see the button "Apply"

  # LAG CONTACTS/MANAGERS
  @dashboards @lag-contacts @lag-managers
  Scenario: Check dashboards functionalitites for LAG Contacts and LAG Managers.
    Given I am logged in as "bdd-user-manager"
    And I have the "LAG Contact" role in the "BDD LAG Published" group
    # LAGS
    When I am at "/my-lags"
    Then I should get a "200" HTTP response
    And I should see the heading "My LAGs"
    And I should see the link "view"
    And I should see the link "manage"
    When I follow "manage"
    Then I should see the heading "Manage my LAG: BDD LAG Published"
    And I should see the link "LAG profile"
    And I should see the link "Cooperation offers"
    And I should see the link "Replies to my Cooperation offers"
    And I should see the link "Contacts"
    And I should see the link "My LAGs"
    And I should see "LAG profile currently online"
    And I should see "LAG name"
    And I should see "Published on"
    And I should see "Published by"
    And I should see "Operations"
    And I should see the link "view"
    And I should see the link "update lag profile"
    When I follow "view"
    Then I should see the heading "LAG Management" in the "right sidebar" region
    Then I should see the link "LAG profile" in the "right sidebar" region
    And I should see the link "Cooperation offers" in the "right sidebar" region
    And I should see the link "Replies to my Cooperation offers" in the "right sidebar" region
    And I should see the link "Contacts" in the "right sidebar" region
    And I should see the link "Contact the Webmaster" in the "right sidebar" region

    # COOPERATION OFFERS
    When I follow "Cooperation offers"
    Then I should see the link "Create a new Cooperation Offer"
    And I should see the heading "Cooperation offers currently online"
    And I should see "BDD COOP"
    And I should see "BDD COOP EXP"
    And I should see the ".coop-offer-expired" element with the "title" attribute set to "Expired" in the "content" region
    And I should see the heading "Cooperation offers update"
    And I should see "BDD COOP DRA"
    And I should see the "#edit-rules-componentrules-enrd-moderate-content-to-ready-to-be-published" element with the "value" attribute set to "Ask for publication" in the "content" region
    And I should see the heading "Cooperation offers pending for publication"
    And I should see "BDD COOP RBP"
    And I should see the heading "Archived cooperation offers"
    And I should see "BDD COOP ARC"
    And I should see the "#edit-rules-componentrules-enrd-moderate-content-to-draft" element with the "value" attribute set to "Create new draft" in the "content" region
    When I click "view" in the "BDD COOP" row
    Then I should see the heading "LAG Management" in the "right sidebar" region
    Then I should see the link "LAG profile" in the "right sidebar" region
    And I should see the link "Cooperation offers" in the "right sidebar" region
    And I should see the link "Replies to my Cooperation offers" in the "right sidebar" region
    And I should see the link "Contacts" in the "right sidebar" region
    And I should see the link "Contact the Webmaster" in the "right sidebar" region

    # CONTACTS
    When I follow "Contacts"
    Then I should see the link "bdd-user-manager"
    And I should see "bdd-user-manager@example.com"

  @javascript @invite
  Scenario: Test the invite form.
    Given I am logged in as "bdd-user-nat-manager"
    And I have the "National manager" role in the "European Agricultural Fund for Rural Development (EAFRD)" group
    When I am at "lag-dashboard"
    And I click "Contacts/Users"
    And I click "Invite/add a user"
    # INVITE FORM
    Then I should see "The user does not have an account yet."
    And I should see "User"
    And I should see "Country"
    And I should see "LAG"
    And I should see "LAG Role"
    And I should see "LAG Contact"
    And I should see "LAG Manager"
    When I press the "Add user" button
    Then I should see the following error messages:
      | error messages             |
      | Country field is required. |
      | User field is required.    |
    When I fill in the autocomplete "edit-username" with "bdd-user-contact" and click "bdd-user-contact (bdd-user-contact)"
    And I select "BDD Belgium" from "Country"
    And I wait for AJAX to finish
    And I set the chosen element "LAG" to "BDD LAG Published (BDD-BE-LAG-PUB)"
    And I press the "Add user" button
    Then I should see the following success messages:
      | success messages                                                                                                    |
      | User bdd-user-contact is now member of BDD LAG Published as LAG Contact. A notification email was sent to the user. |
    When I click "LAG Contacts"
    Then I should see the link "bdd-user-contact"
    And I should see "bdd-user-contact@example.com"

  @javascript @invite
  Scenario: Invite unregistered users.
    Given I am logged in as "bdd-user-nat-manager"
    And I have the "National manager" role in the "European Agricultural Fund for Rural Development (EAFRD)" group
    When I am at "lag-dashboard"
    And I click "Contacts/Users"
    And I click "Invite/add a user"
    # INVITE FORM
    When I check the box "The user does not have an account yet."
    And I fill in "Name and Surname" with "John Test"
    And I fill in "Email" with "johntest@bdd.test"
    And I select "BDD Belgium" from "Country"
    And I wait for AJAX to finish
    And I set the chosen element "LAG" to "BDD LAG Published (BDD-BE-LAG-PUB)"
    And I press the "Send Invitation" button
    Then I should see the following success messages:
      | success messages          |
      | Invitation has been sent. |
    When I retrieve the LAG invite send to "johntest@bdd.test"
    And I am logged in as a user with the "authenticated" role
    And I accept the invite
    Then I should see the following success messages:
      | success messages                                            |
      | You have accepted the invitation from bdd-user-nat-manager. |
    And I should see the heading "My LAGs"
    And I should see "BDD LAG Published" in the "BDD-BE-LAG-PUB" row
