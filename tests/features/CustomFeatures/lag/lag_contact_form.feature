@api @lag @contact-this-lag
Feature: ENRD LAG Database Contact form. Test the submissions related to webform
  attached on every cooperation offer.

  Background: Create a user, a LAG and a Cooperation offer to test contact forms.
    Given "enrd_countries" terms:
      | name        | parent         |
      | BDD Belgium | European Union |
    Given I am viewing a "lag" content in "published" status:
      | title                  | BDD LAG Contact Form                                     |
      | field_enrd_lag_country | BDD Belgium                                              |
      | field_enrd_lag_code    | BDD-BE-LAG-CONTACT                                       |
      | og_group_ref           | European Agricultural Fund for Rural Development (EAFRD) |
      | author                 | bdd-user-webmaster                                       |
      | language               | und                                                      |
    And I am viewing a "lag" content in "published" status:
      | title                  | BDD LAG Another Contact Form                             |
      | field_enrd_lag_country | BDD Belgium                                              |
      | field_enrd_lag_code    | BDD-BE-LAG-ANOTHER-CONTACT                               |
      | og_group_ref           | European Agricultural Fund for Rural Development (EAFRD) |
      | author                 | bdd-user-webmaster                                       |
      | language               | und                                                      |
    And I am viewing a "cooperation_offer" content in "published" status:
      | title                           | BDD COOP CONTACT FORM        |
      | field_enrd_coop_partner_country | BDD Belgium                  |
      | og_lag_group_ref                | BDD LAG Contact Form         |
      | field_enrd_coop_lag_email:email | bdd-coop-manager@example.com |
      | author                          | bdd-user-contact-coop        |
      | language                        | und                          |
    And I am viewing a "cooperation_offer" content in "published" status:
      | title                           | BDD COOP ANOTHER CONTACT FORM |
      | field_enrd_coop_partner_country | BDD Belgium                   |
      | og_lag_group_ref                | BDD LAG Another Contact Form  |
      | field_enrd_coop_lag_email:email | bdd-coop-manager2@example.com |
      | author                          | bdd-user-contact-coop         |
      | language                        | und                           |
    Given users:
      | name              | mail                      | pass | roles                        | field_enrd_lag_country | og_user_node                 |
      | bdd-user1-manager | bdd-user1-man@example.com | test | authenticated user, LAG User | BDD Belgium            | BDD LAG Contact Form         |
      | bdd-user1-contact | bdd-user1-con@example.com | test | authenticated user, LAG User | BDD Belgium            | BDD LAG Contact Form         |
      | bdd-user2-manager | bdd-user2-man@example.com | test | authenticated user, LAG User | BDD Belgium            | BDD LAG Another Contact Form |

  @anonymous @privacy
  Scenario: As Anonymous I want to contact the responsible LAG through the contact form
  available on the right in every Cooperation Offer.
    # As anonymous check that the form is visible and in the right place.
    Given I am an anonymous user
    And I am at "lag/bdd-be-lag-contact/offer/bdd-coop-contact-form"
    Then I should see the heading "Contact this LAG *" in the "right sidebar"
    And I should see "Your organisation" in the "right sidebar" region
    And I should see "Your email" in the "right sidebar" region
    And I should see "Message" in the "right sidebar" region
    When I fill in "edit-submitted-enrd-lag-database-contact-this-lag-your-organisation" with "BDD My Organization"
    And I fill in "edit-submitted-enrd-lag-database-contact-this-lag-your-email" with "bdd-user@example.com"
    And I fill in "edit-submitted-enrd-lag-database-contact-this-lag-message" with "Hello, World!"
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I press the "Submit" button
    # Check that CAPTCHA blocks submissions without image code.
    Then I should see the following error messages:
      | error messages                                |
      | What code is in the image? field is required. |

  @emails @authenticated @lag-managers @lag-contacts @contact-form @privacy
  Scenario: As an authenticated user I should be able to contact the Manager via the contact form.
  As LAG manager/contact I should be able to consult the list of submissions issued for my LAG.
    Given I am logged in as a user with the "authenticated" role and I have the following fields:
      | mail | bdd-auth-user@example.com |
    When I am at "lag/bdd-be-lag-contact/offer/bdd-coop-contact-form"
    And I fill in "edit-submitted-enrd-lag-database-contact-this-lag-your-organisation" with "BDD LAG Inc."
    And I fill in "edit-submitted-enrd-lag-database-contact-this-lag-message" with "BDD - Hello, This is BDD User!"
    And the test email system is enabled
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I press the "Submit" button
    Then the email to "bdd-coop-manager@example.com" should contain "BDD - Hello, This is BDD User!"

    When I am logged in as "bdd-user1-manager"
    And I have the "LAG Manager" role in the "BDD LAG Contact Form" group
    When I am at "lag/bdd-be-lag-contact"
    And I click "Replies to my Cooperation offers"
    Then I should see "bdd-auth-user@example.com" in the "BDD COOP CONTACT FORM" row
    And I should see the link "View" in the "content" region
    But I should not see the link "Edit" in the "content" region
    But I should not see the link "Delete" in the "content" region
    When I follow "View" in the "content" region
    Then I should see "Reply to Cooperation offer: BDD COOP CONTACT FORM" in the "content" region
    And I should see "From: bdd-auth-user@example.com" in the ".webform-component--enrd-lag-database-contact-this-lag-your-email" element
    And I should see "Organisation: BDD LAG Inc." in the ".webform-component--enrd-lag-database-contact-this-lag-your-organisation" element
    And I should see "Subject: Message received for 'BDD COOP CONTACT FORM'" in the ".webform-component--enrd-lag-database-contact-this-lag-subject" element
    And I should see "Message: BDD - Hello, This is BDD User!" in the ".webform-component--enrd-lag-database-contact-this-lag-message" element
    And I should see "LAG contact in charge: bdd-coop-manager@example.com" in the ".webform-component--enrd-lag-database-contact-this-lag-email" element
    And I should see "LAG: BDD LAG Contact Form" in the "content" region

  @emails @lag-managers @contact-form @privacy
  Scenario: As LAG manager I should be able to view a submission of my LAG but not those of another LAG.
    Given I am logged in as "bdd-user2-manager"
    And I have the "LAG Manager" role in the "BDD LAG Another Contact Form" group
    And I am at "lag/bdd-be-lag-another-contact/offer/bdd-coop-another-contact-form"
    When I fill in "edit-submitted-enrd-lag-database-contact-this-lag-your-organisation" with "BDD LAG S.p.a."
    And I fill in "edit-submitted-enrd-lag-database-contact-this-lag-message" with "BDD - Hello, This is BDD User2 Manager!"
    And the test email system is enabled
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I press the "Submit" button
    Then the email to "bdd-coop-manager2@example.com" should contain "BDD - Hello, This is BDD User2 Manager!"
    When I am at "lag/bdd-be-lag-another-contact"
    And I click "Replies to my Cooperation offers"

    Then I should see "bdd-user2-man@example.com" in the "BDD COOP ANOTHER CONTACT FORM" row
    And I should see "BDD COOP ANOTHER CONTACT FORM" in the "bdd-user2-man@example.com" row

    When I am at "lag/bdd-be-lag-contact/offer/bdd-coop-contact-form"
    And I fill in "edit-submitted-enrd-lag-database-contact-this-lag-your-organisation" with "BDD LAG Inc."
    And I fill in "edit-submitted-enrd-lag-database-contact-this-lag-message" with "BDD - Hello, This is BDD User2 Man!"
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I press the "Submit" button
    And I am at "lag/bdd-be-lag-contact"
    Then I should not see the link "Replies to my Cooperation offers" in the "right sidebar"

  @webmaster
  Scenario: as webmaster I should be able to see the list of submissions issued via the contact form.
    Given I am logged in as a user with the "webmaster" role
    When I am at "admin/content/webform"
    And I follow "Contact this LAG"
    And I click "Results"
    Then I should get a "200" HTTP response
