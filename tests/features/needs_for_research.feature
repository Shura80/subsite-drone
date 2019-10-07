@api @nfrfp
Feature: Test for content type Needs For Research From Practice.

  # Create a pre-existing node to check that "Contact person" data is preserved when editing.
  Background:
    Given "tags" terms:
      | name        |
      | BDD Keyword |
    And "core_geographical_area" terms:
      | name        |
      | BDD Belgium |
    And I am viewing a "needs_for_research_from_practice" content in "published" status:
      | title                        | BDD NFRFP            |
      | field_projects_language      | English              |
      | field_body                   | BDD Problem          |
      | field_core_keywords          | BDD Keyword          |
      | field_core_geographical_area | BDD Belgium          |
      | author                       | janedoe              |
      | field_projects_name          | Jane                 |
      | field_projects_surname       | Doe                  |
      | field_core_email:email       | jane_doe@example.com |

  Scenario: Check that in Needs For Research node forms, the "Contact person" fieldgroup fields
  are pre-filled only if the node is new, while editing a node preserves existing data.
    Given I am logged in as a user with the "editor" role and I have the following fields:
      | field_firstname | Ed                    |
      | field_lastname  | Editor                |
      | mail            | ed_editor@example.com |
    And I am at "find-connect/needs-for-research/bdd-nfrfp"
    And I click "New draft"
    Then the "Name" field should contain "Jane"
    Then the "Surname" field should contain "Doe"
    Then the "Contact e-mail" field should contain "jane_doe@example.com"
    When I click "Add content"
    And I click "Needs for research from practice"
    Then the "Name" field should contain "Ed"
    Then the "Surname" field should contain "Editor"
    Then the "Contact e-mail" field should contain "ed_editor@example.com"