@api @online_resources
Feature: Test "Online resources" search page.

  Scenario: As Anonymous I want to search for online resources.
    Given "tags" terms:
      | name                   |
      | BDD Keyword 1          |
      | BDD Keyword 2          |
    And I am viewing an "online_resource" in "published" status:
      | title                  | BDD Online Resource                                     |
      | body                   | Lorem ipsum facilisis tortor iaculis                    |
      | field_core_link        | BDD Website Url - http://www.bdd1-online-resource.com  |
      | field_news_language    | English, German                                         |
      | field_core_keywords    | BDD Keyword 1                                           |
      | language               | und                                                     |
      | created                | 01-01-2019 8:00                                         |
      | changed                | 01-01-2020 8:00                                         |
    And I am viewing an "online_resource" in "published" status:
      | title                  | BDD Test Resource                                       |
      | body                   | Lorem ipsum semper turpis metus                         |
      | field_core_link        | BDD Test Url - http://www.bdd2-online-resource.com     |
      | field_news_language    | Spanish, French                                         |
      | field_core_keywords    | BDD Keyword 2                                           |
      | language               | und                                                     |
      | created                | 03-01-2020 17:00                                        |
      | changed                | 03-01-2020 17:00                                        |

    When I am at "find-connect/online-resources"
    # Check that Title, Description, Link and Language column headings are visible.
    Then I should see "Title" in the ".views-field-title" element
    Then I should see "Description" in the ".views-field-body" element
    Then I should see "Link" in the ".views-field-field-core-link" element
    Then I should see "Language" in the ".views-field-field-news-language" element
    And I fill in "Title" with "BDD"
    And I press "edit-submit-news-online-resources-list"
    # Check that Title, Description, Link and Language info are visible.
    Then I should see "BDD Online Resource" in the ".views-row-first" element
    And I should see "Lorem ipsum facilisis tortor iaculis" in the ".views-row-first" element
    And I should see "BDD Website Url" in the ".views-row-first" element
    And I should see "English, German" in the ".views-row-first" element

    Then I should see "BDD Test Resource" in the ".views-row-last" element
    And I should see "Lorem ipsum semper turpis metus" in the ".views-row-last" element
    And I should see "BDD Test Url" in the ".views-row-last" element
    And I should see "Spanish, French" in the ".views-row-last" element
    # Check Title Full-text filter.
    And I fill in "Title" with "BDD Online"
    And I press "edit-submit-news-online-resources-list"
    Then I should see the link "BDD Online Resource" in the "content" region
    But I should not see the link "BDD Test Resource" in the "content" region
    # Check Keywords filter.
    And I press "Reset"
    And I select "BDD Keyword 1" from "Keywords"
    And I press "edit-submit-news-online-resources-list"
    Then I should see the link "BDD Online Resource" in the "content" region
    But I should not see the link "BDD Test Resource" in the "content" region
    # Check Language filter.
    And I press "Reset"
    And I fill in "Title" with "BDD"
    And I press "edit-submit-news-online-resources-list"
    And I select "Spanish" from "Language"
    And I press "edit-submit-news-online-resources-list"
    Then I should see the link "BDD Test Resource" in the "content" region
    But I should not see the link "BDD Online Resource" in the "content" region
    # Check "Sort by + Order" filter:
    # Title: Asc.
    And I press "Reset"
    And I fill in "Title" with "BDD"
    And I press "edit-submit-news-online-resources-list"
    And I select "Title" from "Sort by"
    And I select "Asc" from "Order"
    And I press "edit-submit-news-online-resources-list"
    Then I should see "BDD Online Resource" in the ".views-row-first" element
    And I should see "BDD Test Resource" in the ".views-row-last" element
    # Title: Desc.
    And I press "Reset"
    And I fill in "Title" with "BDD"
    And I press "edit-submit-news-online-resources-list"
    And I select "Title" from "Sort by"
    And I select "Desc" from "Order"
    And I press "edit-submit-news-online-resources-list"
    Then I should see "BDD Test Resource" in the ".views-row-first" element
    And I should see "BDD Online Resource" in the ".views-row-last" element
    # Post date: Desc.
    And I press "Reset"
    And I fill in "Title" with "BDD"
    And I press "edit-submit-news-online-resources-list"
    And I select "Post date" from "Sort by"
    And I select "Desc" from "Order"
    And I press "edit-submit-news-online-resources-list"
    Then I should see "BDD Test Resource" in the ".views-row-first" element
    And I should see "BDD Online Resource" in the ".views-row-last" element
    # Post date: Asc.
    And I press "Reset"
    And I fill in "Title" with "BDD"
    And I press "edit-submit-news-online-resources-list"
    And I select "Post date" from "Sort by"
    And I select "Asc" from "Order"
    And I press "edit-submit-news-online-resources-list"
    Then I should see "BDD Online Resource" in the ".views-row-first" element
    And I should see "BDD Test Resource" in the ".views-row-last" element
