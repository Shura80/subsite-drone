@api @taxonomies
Feature: ENRD Tagging system

  This feature is aimed to add a new set of taxonomies to the ENRD website.
  It also adds term reference fields on content types.

  As editor I want to tag content by categories.

  Background: Technical and Classification terms are loaded

    # Technical Taxonomies
    Given 'enrd_translation_status' terms:
      | name                   |
      | BDD Translation status |
    And 'enrd_origin' terms:
      | name       |
      | BDD Origin |
    And 'enrd_update_status' terms:
      | name       |
      | BDD Status |

    # Classifications Taxonomies
    And 'enrd_countries' terms:
      | name        |
      | BDD Country |
    And 'enrd_languages' terms:
      | name         |
      | BDD Language |
    And 'enrd_transversal_topics' terms:
      | name      |
      | BDD Topic |
    And 'enrd_rural_development_policy' terms:
      | name          |
      | BDD RD Policy |
    And 'enrd_evaluation' terms:
      | name           |
      | BDD Evaluation |

  @javascript @editor
  Scenario: I can create a new node and tag it.
    Given I am logged in as a user with the "editor" role

    When I am on content add "page"

    And I enter "BDD Classified basic page" for "edit-title-field-en-0-value"

    And I click "Technical taxonomy"
    And I select "BDD Translation status" from "Translation status"
    And I select "BDD Origin" from "Origin"
    And I select "BDD Status" from "Update status"

    And I click "Classification"
    And I select "BDD Country" from hierarchical select "Country"
    And I select "BDD Language" from hierarchical select "Language"
    And I select "BDD Topic" from hierarchical select "Transversal topics"
    And I select "BDD RD Policy" from hierarchical select "Rural Development Policy"
    And I set the chosen element "Evaluation" to "BDD Evaluation"

    And I press "Save"
    Then I should see the success message "Basic page BDD Classified basic page has been created."

  @javascript @editor
  Scenario: I can see tag for an existing page.

    Given I am logged in as a user with the "editor" role
    And I am viewing a "page" content:
      | title                        | BDD Yet another classified page |
      | field_tax_country            | BDD Country                     |
      | field_tax_evaluation         | BDD Evaluation                  |
      | field_tax_languages          | BDD Language                    |
      | field_tax_origin             | BDD Origin                      |
      | field_tax_rural_dev_policy   | BDD RD Policy                   |
      | field_tax_translation_status | BDD Translation status          |
      | field_tax_transversal_topics | BDD Topic                       |
      | field_tax_update_status      | BDD Status                      |
    When I click "Edit draft"
    Then the option "BDD Translation status" from select "Translation status" is selected
    And the option "BDD Origin" from select "Origin" is selected
    And the option "BDD Status" from select "Update status" is selected
    And the option "BDD Country" from hierarchical select "Country" is selected
    And the option "BDD Language" from hierarchical select "Language" is selected
    And the option "BDD Topic" from hierarchical select "Transversal topics" is selected
    And the option "BDD RD Policy" from hierarchical select "Rural Development Policy" is selected
    And the option "BDD Evaluation" from select "Evaluation" is selected
