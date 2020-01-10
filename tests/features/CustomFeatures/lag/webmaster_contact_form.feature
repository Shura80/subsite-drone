@api @lag @contact-webmaster
Feature: ENRD LAG Dashboard: "Contact the Webmaster" contact form.
  This feature is aimed at allowing LAG manager/contact users and National managers to contact the LAG Webmaster
  by providing a tab called "Contact the Webmaster" on their respective dashboard.
  The contact form should be reachable either from their dashboard or when viewing or editing a LAG that their
  are allowed to manage.

  Background: Create different countries and LAGs to test the accessibility to the contact form.
    Given "enrd_countries" terms:
      | name        | parent         |
      | BDD Austria | European Union |
      | BDD Belgium | European Union |
    Given I am viewing a "lag" content in "published" status:
      | title                  | BDD LAG Austria                                          |
      | field_enrd_lag_country | BDD Austria                                              |
      | field_enrd_lag_code    | BDD-AUSTRIA-001                                          |
      | og_group_ref           | European Agricultural Fund for Rural Development (EAFRD) |
      | language               | und                                                      |

  @dashboards @emails @lag-managers @lag-contacts
  Scenario Outline: as LAG manager and LAG contact I should be able to access the contact form of my LAG
    from my dashboard and send a message to the LAG Webmaster.
    Given I am logged in as a user with the "LAG User" role and I have the following fields:
      | mail               | <mail>         |
    And I have the "<role>" role in the "<group>" group
    When I am at "/my-lags"
    And I click "manage" in the "BDD LAG Austria" row
    And I click "Contact the Webmaster"
    And I fill in "Subject" with "<message> - This is the subject of my message"
    And I fill in "Message" with "<message> - This is my message."
    And the test email system is enabled
    And I press the "Submit" button
    Then I should get a "200" HTTP response
    And the email to "<mail>" should contain "<message> - This is the subject of my message"
    And the email to "<mail>" should contain "<message> - This is my message."

    Examples:
      | role           | mail                            | group           | message         |
      | LAG Manager    | bdd-at-user-manager@example.com | BDD LAG Austria | BDD LAG Manager |
      | LAG Contact    | bdd-at-user-contact@example.com | BDD LAG Austria | BDD LAG Contact |

  @dashboards @emails @nsu
  Scenario: as National manager I should be able to access the contact form of my LAG
  from my dashboard and send a message to the LAG Webmaster.
    Given I am logged in as a user with the "LAG User" role and I have the following fields:
      | mail                   | bdd-at-nsu-user@example.com |
      | field_enrd_lag_country | BDD Austria                 |
    And I have the "National manager" role in the "European Agricultural Fund for Rural Development (EAFRD)" group
    When I am at "/lag-dashboard/contact-webmaster"
    And I click "Contact the Webmaster"
    And I fill in "Subject" with "BDD NSU - This is the subject of my message"
    And I fill in "Message" with "BDD NSU - This is my message."
    And the test email system is enabled
    And I press the "Submit" button
    Then I should get a "200" HTTP response
    And the email to "bdd-at-nsu-user@example.com" should contain "BDD NSU - This is the subject of my message"
    And the email to "bdd-at-nsu-user@example.com" should contain "BDD NSU - This is my message."

  @dashboards @webmasters
  Scenario: as Webmaster I should not be able to access the contact form from my Dashboard.
    Given I am logged in as a user with the "administrator, LAG User" roles
    When I go to "lag-dashboard/contact-webmaster"
    Then I should not see the link "Contact the Webmaster"
    And I should get a "403" HTTP response

  @dashboards @lags @lag-managers @lag-contacts
  Scenario Outline: as LAG manager and LAG contact I should be able to access the contact form of my LAG while
    viewing its page.
    I should also not be able to see the list of contact form submissions.
    Given I am logged in as a "LAG User"
    And I have the "<role>" role in the "<group>" group
    When I go to "/lag/bdd-austria-001"
    Then I should see the link "Contact the Webmaster"
    And I click "Contact the Webmaster"
    Then I should not see the link "Results"

    Examples:
      | role         | group            |
      | LAG Manager  | BDD LAG Austria  |
      | LAG Contact  | BDD LAG Austria  |

  @dashboards @lags @webmasters
  Scenario: as Webmaster I should not be able to access the contact form while viewing a LAG.
    I should also be able to see the list of submissions issued via the contact form.
    Given I am logged in as a user with the "administrator, LAG User" roles
    When I go to "/lag/bdd-austria-001"
    Then I should not see the link "Contact the Webmaster"

    When I am at "admin/content/webform"
    Then I click "Contact the Webmaster"
    And I click "Results"
    Then I should get a "200" HTTP response
