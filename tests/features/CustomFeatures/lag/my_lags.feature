@api @my_lags @lag-contacts @dashboards
Feature: ENRD LAG Dashboard: My LAGs.
  This Feature is aimed at testing the "My LAGs" LAG Manager/contact Dashboard,
  where LAG users can manage LAGs and Cooperation offers and
  add/invite to join/remove LAG manager/contact users.

  Background: Create a LAG node to test the different functionalities.
    Given 'enrd_countries' terms:
      | name      | parent         |
      | BDD Italy | European Union |
    And 'enrd_esif_programme' terms:
      | name             | parent    |
      | BDD Italy        | EAFRD     |
      | BDD Programme IT | BDD Italy |
    Given I am viewing a "lag" content in "published" status:
      | title                     | BDD LAG Published                                        |
      | field_enrd_lag_country    | BDD Italy                                                |
      | field_enrd_esif_programme | BDD Programme IT                                         |
      | field_enrd_lag_code       | BDD-IT-LAG-PUB                                           |
      | og_group_ref              | European Agricultural Fund for Rural Development (EAFRD) |
      | language                  | und                                                      |

  Scenario: As LAG Contact I should be able to navigate my LAGs area.
    Given I am logged in as a user with the "LAG User" roles and I have the following fields:
      | mail                   | bdd-lag-contact@example.com |
      | field_enrd_lag_country | BDD Italy                   |
    And I have the "LAG Contact" role in the "BDD LAG Published" group
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

  Scenario: As LAG Manager I should be able to navigate my Cooperation offers area.
    Given I am logged in as a user with the "LAG User" roles and I have the following fields:
      | mail                   | bdd-lag-manager@example.com |
      | field_enrd_lag_country | BDD Italy                   |
    And I am viewing a "cooperation_offer" content in "draft" status:
      | title                           | BDD COOP DRA      |
      | field_enrd_coop_partner_country | BDD Italy         |
      | field_enrd_coop_expiry_date     | 31-12-2019 09:00  |
      | og_lag_group_ref                | BDD LAG Published |
      | language                        | und               |
    And I am viewing a "cooperation_offer" content in "ready_to_be_published" status:
      | title                           | BDD COOP RBP      |
      | field_enrd_coop_partner_country | BDD Italy         |
      | field_enrd_coop_expiry_date     | 31-12-2023 09:00  |
      | og_lag_group_ref                | BDD LAG Published |
      | language                        | und               |
    And I am viewing a "cooperation_offer" content in "published" status:
      | title                           | BDD COOP          |
      | field_enrd_coop_partner_country | BDD Italy         |
      | field_enrd_coop_expiry_date     | 31-12-2023 09:00  |
      | og_lag_group_ref                | BDD LAG Published |
      | language                        | und               |
    And I am viewing a "cooperation_offer" content in "published" status:
      | title                           | BDD COOP EXP      |
      | field_enrd_coop_partner_country | BDD Italy         |
      | field_enrd_coop_expiry_date     | 31-12-2017 09:00  |
      | og_lag_group_ref                | BDD LAG Published |
      | language                        | und               |
    And I am viewing a "cooperation_offer" content in "archived" status:
      | title                           | BDD COOP ARC      |
      | field_enrd_coop_partner_country | BDD Italy         |
      | field_enrd_coop_expiry_date     | 31-12-2023 09:00  |
      | og_lag_group_ref                | BDD LAG Published |
      | language                        | und               |
    And I have the "LAG Manager" role in the "BDD LAG Published" group
    When I am at "/my-lags"
    And I follow "manage"
    Then I should see the heading "Manage my LAG: BDD LAG Published"
    And I follow "Cooperation offers"
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

  @javascript
  Scenario: As LAG Manager I should be able to add an active user as LAG manager/contact,
  and to see but not add a blocked user.
  I should also be able to remove a LAG Manager user through my Dashboard.
    Given users:
      | name             | mail                         | status |
      | bdd-user-active  | bdd-user-active@example.com  | 1      |
      | bdd-user-blocked | bdd-user-blocked@example.com | 0      |
    Given I am logged in as a user with the "LAG User" roles and I have the following fields:
      | name                   | bdd-lag-manager             |
      | mail                   | bdd-lag-manager@example.com |
      | field_enrd_lag_country | BDD Italy                   |
    And I have the "LAG Manager" role in the "BDD LAG Published" group
    When I am at "/my-lags"
    And I follow "manage"
    Then I should see the heading "Manage my LAG: BDD LAG Published"
    When I follow "Contacts"
    Then I should see the link "bdd-lag-manager"
    And I should see "bdd-lag-manager@example.com"

    When I click "Invite/add a user"
    Then I should see "The user does not have an account yet."
    And I should see "User"
    And I should see "Country"
    And I should see "LAG"
    And I should see "LAG Role"
    And I should see "LAG Contact"
    And I should see "LAG Manager"
    When I press the "Add user" button
    Then I should see the following error messages:
      | error messages          |
      | User field is required. |
    When I fill in "edit-username" with "bdd-user-blocked"
    And I press the "Add user" button
    Then I should see the following error messages:
      | error messages                                                                                               |
      | User bdd-user-blocked (bdd-user-blocked) is blocked. Please contact the LAG webmaster to request activation. |
    When I fill in the autocomplete "edit-username" with "bdd-user-active" and click "bdd-user-active (bdd-user-active)"
    And I press the "Add user" button
    Then I should see the following success messages:
      | success messages                                                                                                   |
      | User bdd-user-active is now member of BDD LAG Published as LAG Contact. A notification email was sent to the user. |
    Then I should see the link "bdd-user-active"
    And I should see "bdd-user-active@example.com"
    But I should not see "bdd-user-blocked@example.com"

    # Remove user.
    When I check the box "edit-views-bulk-operations-0"
    And I press "Remove from LAG"
    And I press "Confirm"
    And I wait for the batch job to finish
    Then I should see the following success messages:
      | success messages                     |
      | Performed Remove from LAG on 1 item. |
    And I should not see the link "bdd-user-active"
    And I should not see "bdd-user-active@example.com"

  @invite
  Scenario: As LAG Contact I should be able to invite an unregistered user to join a LAG as LAG contact.
    Given I am logged in as a user with the "LAG User" roles and I have the following fields:
      | name                   | bdd-lag-contact             |
      | mail                   | bdd-lag-contact@example.com |
      | field_enrd_lag_country | BDD Italy                   |
    And I have the "LAG Contact" role in the "BDD LAG Published" group
    When I am at "/my-lags"
    And I follow "manage"
    Then I should see the heading "Manage my LAG: BDD LAG Published"
    When I follow "Contacts"
    And I click "Invite/add a user"
    Then I check the box "The user does not have an account yet."
    And I fill in "Name and Surname" with "John Doe"
    And I fill in "Email" with "johndoe@bdd.test"
    And I press the "Send Invitation" button
    Then I should see the following success messages:
      | success messages          |
      | Invitation has been sent. |
    When I retrieve the LAG invite send to "johndoe@bdd.test"
    And I am logged in as a user with the "authenticated" role
    And I accept the invite
    Then I should see the following success messages:
      | success messages                                       |
      | You have accepted the invitation from bdd-lag-contact. |
    And I should see the heading "My LAGs"
    And I should see "BDD LAG Published" in the "BDD-IT-LAG-PUB" row
