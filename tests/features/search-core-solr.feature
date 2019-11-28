@api @solr
Feature: Test functionality of search site core

  Scenario: As anonymous user I search content and check search page layout.
    # Create a published Basic Page.
    Given I am viewing a "page" content in "published" status:
      | title | BDD page published                                       |
      | body  | Lorem ipsum dolor sit amet, consectetur adipiscing elit. |
    # Create a draft Basic Page.
    And I am viewing a "page" content in "draft" status:
      | title | BDD page draft                                           |
      | body  | Lorem ipsum dolor sit amet, consectetur adipiscing elit. |
    And I send the "page" to the Solr search index
    When I am on "/search/site/"
    Then I should see the text "Filter by content type" in the "sidebar_left" region
    And I should see the text "Sort by" in the "sidebar_right" region
    When I fill in "edit-keys" with "BDD page"
    And I press the "Search" button
    Then I should see "BDD page published" in the "content" region
    But I should not see "BDD page draft" in the "content" region

  Scenario Outline: Check for bundles that shows a Solr related content block.
    # Crate content of any type that is supposed to be searchable and check related content.
    Given I am logged in as a user with the "administrator" role
    And "tags" terms:
      | name        |
      | BDD Keyword |
    # Bundle type node
    And I am viewing a "<bundle>" content in "published" status:
      | title               | BDD related TEST |
      | field_core_keywords | <keyword>        |
    And I remember the node ID of this page
    And I am viewing a "<related_type_1>" content in "published" status:
      | title               | BDD related <related_type_1> |
      | field_core_keywords | <keyword>                    |
    And I am viewing a "<related_type_2>" content in "published" status:
      | title               | BDD related <related_type_2> |
      | field_core_keywords | <keyword>                    |
    And I am viewing a "<related_type_3>" content in "published" status:
      | title               | BDD related <related_type_3> |
      | field_core_keywords | <keyword>                    |
    And I am viewing a "<related_type_4>" content in "published" status:
      | title               | BDD related <related_type_4> |
      | field_core_keywords | <keyword>                    |
    And I am viewing a "<related_type_5>" content in "published" status:
      | title               | BDD related <related_type_5> |
      | field_core_keywords | <keyword>                    |
    # Fixed node to show in "Shoe more" page.
    And I am viewing a "page" content in "published" status:
      | title               | BDD ADDITIONAL |
      | field_core_keywords | BDD Keyword    |
    # Send content to Solr.
    And I send the "<related_type_1>,<related_type_2>,<related_type_3>,<related_type_4>,<related_type_5>" to the Solr search index
    And I go to the page of the node I remembered

    # Check if related block exists and what content it displays.
    Then I should see "Related content"
    And I should see the link "BDD related <related_type_1>" in the "<region>" region
    And I should see the link "BDD related <related_type_2>" in the "<region>" region
    And I should see the link "BDD related <related_type_3>" in the "<region>" region
    And I should see the link "BDD related <related_type_4>" in the "<region>" region
    And I should see the link "BDD related <related_type_5>" in the "<region>" region
    But I should not see the link "BDD ADDITIONAL" in the "<region>" region
    And I should see the link "Show more" in the "<region>" region
    When I click "Show more" in the "<region>" region
    Then I should see the link "BDD ADDITIONAL"
    And I should see "More related content for BDD related TEST"
    And I should see the link "Back"
    When I click "Back"
    Then I should see the heading "BDD related TEST"


    Examples:
      | bundle        | keyword     | related_type_1 | related_type_2 | related_type_3 | related_type_4 | related_type_5 | region         |
      | news          | BDD Keyword | news           | event          | press_release  | publication    | page           | sidebar_left   |
      | event         | BDD Keyword | news           | event          | press_release  | publication    | page           | content_bottom |
      | press_release | BDD Keyword | news           | event          | press_release  | publication    | page           | sidebar_left   |

  @javascript
  Scenario: Check that for pages the block is displayed only if it is a focus-group.
    # Create content to be searched as related for focus groups but not for standard pages.
    Given I am logged in as a user with the "administrator" role
    And "tags" terms:
      | name              |
      | BDD Keyword       |
      | BDD Other Keyword |
    And I am viewing a "page" content in "published" status:
      | title               | BDD related PAGE |
      | field_core_keywords | BDD Keyword      |
    And I am viewing a "page" content in "published" status:
      | title               | BDD related TEST |
      | field_core_keywords | BDD Keyword      |
    And I remember the node ID of this page
    And I send the "page" to the Solr search index
    And I go to the page of the node I remembered
    Then I should not see the link "BDD related PAGE"
    And I am viewing a "page" content in "published" status:
      | title                           | BDD related focus group |
      | field_core_keywords             | BDD Keyword             |
      | field_agri_pages_is_focus_group | 1                       |
    And I remember the node ID of this page
    And I send the "page" to the Solr search index
    And I go to the page of the node I remembered
    And I click "New draft"
    And I click "URL path settings"
    And I uncheck the box "Generate automatic URL alias"
    And I fill in "URL alias" with "focus-groups/bdd-related-focus-group"
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I press "Save"
    Then I should see "Related content" in the "content" region
