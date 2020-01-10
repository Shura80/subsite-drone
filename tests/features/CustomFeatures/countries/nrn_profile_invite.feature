@api @nrn_profiles @invite
Feature: ENRD NRN Profiles Invite

  This function aims to test the possibility of administrative roles, the invitation of registered and unregistered users, to edit an NRN Profile.

  Scenario: I validate a invite form as administrator role
    Given I am viewing an "nrn_profile" content in "published" status:
      | title | BDD NRN Profile |
    And I am logged in as a user with the "administrator" role
    And I am at "admin/enrd/nrn-profiles/editors"
    And I click "Invite/add a user"
    # INVITE FORM VALIDATION
    Then I should see "Create ENRD NRN Profiles invitation"
    And I should see "User"
    And I should see "NRN Profile"
    When I press the "Add user" button
    Then I should see the following error messages:
      | error messages                 |
      | NRN Profile field is required. |
      | User field is required.        |
    When I check the box "The user does not have an account yet."
    And I should see "Name and Surname"
    And I should see "Email"
    And I should see "NRN Profile"
    When I press the "Send invitation" button
    Then I should see the following error messages:
      | error messages                      |
      | Email field is required.            |
      | Name and Surname field is required. |
      | NRN Profile field is required.      |

  Scenario: I invite an existing user to edit an NRN profile
    Given I am viewing an "nrn_profile" content in "published" status:
      | title | BDD NRN Profile |
    And users:
      | name          | mail                      | roles              |
      | bdd-user-test | bdd-user-test@example.com | authenticated user |
    And I am logged in as a user with the "administrator" role
    And I am at "admin/enrd/nrn-profiles/editors"
    And I click "Invite/add a user"
    When I should see "Create ENRD NRN Profiles invitation"
    And I fill in "edit-username" with "bdd-user-test"
    And I fill in "edit-field-enrd-nrnp-invite-page-und-0-target-id" with "BDD NRN Profile"
    And I press the "Add user" button
    Then I should see the following success messages:
      | success messages                                                                                   |
      | User bdd-user-test is now an editor of BDD NRN Profile. A notification email was sent to the user. |
    When I am at "admin/enrd/nrn-profiles/editors"
    Then I should see the link "bdd-user-test"

  Scenario: I invite through email an user to edit an NRN profile
    Given I am viewing an "nrn_profile" content in "published" status:
      | title | BDD NRN Profile |
    And I am logged in as a user with the "administrator" role
    And I am at "admin/enrd/nrn-profiles/editors"
    And I click "Invite/add a user"
    Then I should see "Create ENRD NRN Profiles invitation"
    When I check the box "The user does not have an account yet."
    And I fill in "edit-field-enrd-nrnp-invite-name-und-0-value" with "John Doe"
    And I fill in "edit-field-enrd-nrnp-invite-email-und-0-email" with "johndoe@bdd.test"
    And I fill in "edit-field-enrd-nrnp-invite-page-und-0-target-id" with "BDD NRN Profile"
    And I press the "Send invitation" button
    Then I should see the following success messages:
      | success messages          |
      | Invitation has been sent. |
    When I retrieve the NRN invite send to "johndoe@bdd.test"
    And I am logged in as a user with the "authenticated" role
    And I accept the invite
    Then I should see the heading "BDD NRN Profile"
    And I should see the link "New draft"
