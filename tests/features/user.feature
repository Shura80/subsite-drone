@api @users
Feature: Test website login functionalities and users management

  #Test empty login for error messages
  Scenario: Check the login functionality
    Given I am an anonymous user
    And I am on "/user"
    When I fill in "Username" with ""
    And  I fill in "Password" with ""
    When I press "Log in"
    Then I should see the error message "Username field is required."
    And I should see the error message "Password field is required."

  Scenario: Check that users of type "Adviser" can see an additional tab in Search people page.
    Given I am logged in as a user with the "editor" role and I have the following fields:
      | field_user_type | Adviser |
    When I go to "find-people/advisors"
    Then I should get a 200 HTTP response

  Scenario: Check that non "Adviser" users cannot see the additional tab in Search people page.
    Given I am logged in as a user with the "editor" role and I have the following fields:
      | field_user_type | Researcher |
    When I go to "find-people/advisors"
    Then I should get an access denied error
