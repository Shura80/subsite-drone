@api @digitisation
Feature: This feature aim to setup tests for both backend and frontend
  of EIP-AGRI Digitisation Toolbox section.

  @javascript @digitisation-backend
  Scenario: Check access to backend views and flagging/bulk operations for allowed users.
    Given I am logged in as a user with the "administrator" role
    And "core_geographical_area" terms:
      | name        |
      | BDD Belgium |
      | BDD Italy   |
    And "tags" terms:
      | name             |
      | BDD Digitisation |
      | BDD Digital HUB  |
    And I am viewing a "news" content in "published" status:
      | title                        | BDD Digitisation Flagged News |
      | field_core_geographical_area | BDD Belgium                   |
      | field_core_keywords          | BDD Digitisation              |
      | field_news_publication_date  | 01-01-2019 09:00              |
      | language                     | und                           |
    # Check flagging/unflagging node with Digitisation toolbox flag.
    When I am at "admin/content/digitisation-toolbox"
    And I should see "Digitisation toolbox - Other content"
    And I should see "EDIT VALUES"
    And I should see the button "Add items"
    And I should see the button "Remove items"
    And I should see the button "Update keywords and country"
    And I should see the text "BDD Digitisation" in the "BDD Digitisation Flagged News" row
    And I should see the text "BDD Belgium" in the "BDD Digitisation Flagged News" row
    And I click "Add to Digitisation toolbox" in the "BDD Digitisation Flagged News" row
    And I wait for AJAX to finish
    And I follow "BDD Digitisation Flagged News"
    Then I should see the link "Remove from Digitisation toolbox" in the "content" region
    When I click "Remove from Digitisation toolbox"
    And I wait for AJAX to finish
    Then I should see "Add to Digitisation toolbox"
    #Check bulk operation to edit Country/keywords.
    When I am at "admin/content/digitisation-toolbox"
    Given I check the box "edit-views-bulk-operations-0"
    And I press the "Update keywords and country" button
    And I check the box "bundle_news[show_value][field_core_geographical_area]"
    And I check the box "bundle_news[show_value][field_core_keywords]"
    And I set the chosen element "edit-bundle-news-field-core-geographical-area-und" to "BDD Italy"
    And I set the chosen element "edit-bundle-news-field-core-keywords-und" to "BDD Digital HUB"
    And I press the "Next" button
    And I press the "Confirm" button
    And I wait for AJAX to finish
    # Reload just to be shure the page is updated.
    And I am at "admin/content/digitisation-toolbox"
    # New keyword(s) added to the existing by default, instead of overwrite old values.
    And I should see the text "BDD Digitisation, BDD Digital HUB" in the "BDD Digitisation Flagged News" row
    # Country is replaced with new value by default.
    And I should see the text "BDD Italy" in the "BDD Digitisation Flagged News" row

  @javascript @digitisation-frontend @digitisation-navigation @solr
  Scenario: Check if Digitisation toolbox landing page and internal pages contain needed block and works like expected when filtering by country.
    Given I am logged in as a user with the "administrator" role
    And "core_geographical_area" terms:
      | name        |
      | BDD Belgium |
      | BDD Italy   |
    And "tags" terms:
      | name             |
      | BDD Digitisation |
      | BDD Digital HUB  |
    # Create 1 node per type of bundles displayed in landing page.
    And I am viewing a "news" in "published" status:
      | title                        | BDD Digitisation News |
      | field_core_geographical_area | BDD Italy             |
      | field_core_keywords          | BDD Digital HUB       |
      | field_news_publication_date  | 01-01-2019 09:00      |
      | language                     | und                   |
    And I am viewing a "publication" in "published" status:
      | title                        | BDD Digitisation Publication     |
      | field_core_title_eng         | BDD Digitisation Publication ENG |
      | field_publications_authors   | BDD Pub Author                   |
      | field_publication_type       | Report                           |
      | field_publication_abstract   | Lorem ipsum                      |
      | field_publication_date       | 2019                             |
      | field_core_geographical_area | BDD Italy                        |
      | field_core_keywords          | BDD Digital HUB                  |
      | language                     | und                              |
    # Set another publication with non matching country.
    And I am viewing a "publication" in "published" status:
      | title                        | BDD Digitisation Publication Excluded     |
      | field_core_title_eng         | BDD Digitisation Publication Excluded ENG |
      | field_publications_authors   | BDD Pub Author                            |
      | field_publication_type       | Report                                    |
      | field_publication_abstract   | Lorem ipsum                               |
      | field_publication_date       | 2019                                      |
      | field_core_geographical_area | BDD Belgium                               |
      | field_core_keywords          | BDD Digitisation                          |
      | language                     | und                                       |
    And I am viewing a "project" in "published" status:
      | title                          | BDD Digitisation Project     |
      | field_proj_title_eng           | BDD Digitisation Project ENG |
      | field_proj_problems            | BDD Problems                 |
      | field_proj_problems_eng        | BDD Problems ENG             |
      | field_publication_abstract     | Lorem ipsum                  |
      | field_proj_geographical_area   | BDD Belgium                  |
      | field_core_keywords            | BDD Digitisation             |
      | field_proj_funding_source_list | Other EU research funds      |
      | field_proj_contact_e-mail      | bdd_digitisation@example.com |
      | language                       | und                          |
    # Set two basic pages (one focus group) to test the related content inside Digitisation toolbox.
    # Standard page.
    And I am viewing a "page" in "published" status:
      | title                        | BDD Digitisation Related page |
      | field_core_keywords          | BDD Digital HUB               |
      | field_core_geographical_area | BDD Italy                     |
      | language                     | und                           |
    # Focus group.
    And I am viewing a "page" in "published" status:
      | title                           | BDD Digitisation Focus Group |
      | field_core_keywords             | BDD Digital HUB              |
      | field_agri_pages_is_focus_group | 1                            |
      | field_core_geographical_area    | BDD Belgium                  |
      | language                        | und                          |
    # Create a Digitisation toolbox page content with menu link.
    And I am at "node/add/digitisation-toolbox"
    Then I should see "Create Digitisation Toolbox page"
    When I fill in "Title" with "BDD Digitisation Page"
    And I set the chosen element "edit-field-core-keywords-und" to "BDD Digital HUB"
    And I click "Menu settings"
    And I check the box "Provide a menu link"
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I press the "Save" button
    # Bulk flag as Digitisation Toolbox selected nodes (projects).
    When I am at "admin/content/digitisation-toolbox/projects"
    And I fill in "Title" with "BDD Digitisation Project"
    And I press "Apply"
    And I wait for AJAX to finish
    And I check the box "edit-views-bulk-operations-0"
    And I press the "Add items" button
    And I wait for the batch job to finish
    Then I am at "admin/content/digitisation-toolbox"
    # Bulk flag as Digitisation Toolbox selected nodes (other content).
    And I check the box "edit-views-bulk-operations-0"
    And I check the box "edit-views-bulk-operations-1"
    And I check the box "edit-views-bulk-operations-2"
    And I check the box "edit-views-bulk-operations-3"
    And I check the box "edit-views-bulk-operations-4"
    And I press the "Add items" button
    And I wait for the batch job to finish
    And I am at "digitising-agriculture"
    And I click "BDD Digitisation Page"
    # Check internal page with no country filter applied.
    Then I should see the link "Digitising Agriculture" in the "sidebar_left" region
    And I should see the link "BDD Digitisation Page" in the "sidebar_left" region
    And I should see "BDD Digitisation News" in the "content_top_left" region
    And I should see "BDD Digitisation Publication" in the "content_top_left" region
    And I should see "BDD Digitisation Focus Group" in the "content_top_left" region
    # Check that the first menu link (block title) always leads to Digitisation splash page.
    When I click "Digitising Agriculture" in the "sidebar_left" region
    Then I should see the heading "Digitising Agriculture"
    # Check that also breadcrumb leads to splash page.
    When I click "BDD Digitisation Page"
    Then I should see the link "Digitising Agriculture" in the "featured" region
    When I click "Digitising Agriculture" in the "featured" region
    Then I should see the heading "Digitising Agriculture"
    # Check the landing page.
    When I am at "digitising-agriculture"
    # Solr index for related content.
    And I send the "digitisation_toolbox, page" to the Solr search index
    Then I should see the link "BDD Digitisation News" in the "content_top" region
    And I should see the link "BDD Digitisation Publication" in the "sidebar_right" region
    And I should see the link "BDD Digitisation Project" in the "content_top_left" region
    And I should see the link "BDD Digitisation Page" in the "content_top_right" region
    # Now filter by BDD Italy to be sure that the other contents, tagged with BDD Belgium, disappear.
    When I set the chosen element "edit-country" to "BDD Italy"
    Then I should see the link "BDD Digitisation News" in the "content_top" region
    And I should see the link "BDD Digitisation Publication" in the "sidebar_right" region
    # These publication and project have different country, so it should not appear in filtered splash page.
    But I should not see "BDD Digitisation Publication Excluded" in the "sidebar_right" region
    And I should not see the link "BDD Digitisation Project"
    When I click "BDD Digitisation Page" in the "content_top_right" region
    Then I should see "BDD Digitisation Publication" in the "content_top_left" region
    # Related content
    And I should see the link "BDD Digitisation Related page" in the "content_top_left" region
    But I should not see the link "BDD Digitisation Focus Group" in the "content_top_left" region
    # This publication has same country but non-matching tag, so it should not appear in internal filtered page.
    And I should not see "BDD Digitisation Publication Excluded" in the "content_top_left" region
    # Check that go back link preserve country filter if it has been set.
    When I click "Digitising Agriculture" in the "sidebar_left" region
    Then I should see the link "BDD Digitisation News" in the "content_top" region
    And I should see the link "BDD Digitisation Publication" in the "sidebar_right" region
    But I should not see "BDD Digitisation Publication Excluded" in the "sidebar_right" region
    And I should not see the link "BDD Digitisation Project"

  @anonymous @digitisation-frontend @search_api_node
  Scenario: As Anonymous I want to view the list of Projects flagged by Digitisation and use filters to search for them.
    Given I am logged in as a user with the "administrator" role
    And "core_geographical_area" terms:
      | name        |
      | BDD Belgium |
      | BDD Denmark |
    And "tags" terms:
      | name                             |
      | BDD Digitisation                 |
      | BDD Animal husbandry and welfare |
    And I am viewing a "project" in "published" status:
      | title                          | BDD Digitisation Project 1                 |
      | field_proj_geographical_area   | BDD Belgium                                |
      | field_core_keywords            | BDD Animal husbandry and welfare           |
      | field_proj_funding_source_list | Other EU research funds                    |
      | field_proj_problems            | Lorem ipsum auctor risus et vestibulum     |
      | field_proj_problems_eng        | Lorem ipsum sem morbi hac eros             |
      | field_proj_desc                | Lorem ipsum donec fringilla curabitur      |
      | field_proj_desc_eng            | Lorem ipsum mi sollicitudin hendrerit nisl |
      | language                       | und                                        |
    And I am viewing a "project" in "published" status:
      | title                          | BDD Digitisation Project 2                |
      | field_proj_geographical_area   | BDD Denmark                               |
      | field_core_keywords            | BDD Digitisation                          |
      | field_proj_funding_source_list | Other EU research funds                   |
      | field_proj_problems            | Lorem ipsum pellentesque lobortis aliquam |
      | field_proj_problems_eng        | Lorem ipsum nisi lacus congue lorem       |
      | field_proj_desc                | Lorem ipsum convallis vestibulum proin    |
      | field_proj_desc_eng            | Lorem ipsum ut inceptos mi faucibus       |
      | language                       | und                                       |
    And I am viewing a "project" in "published" status:
      | title                          | BDD Digitisation Project 3       |
      | field_proj_geographical_area   | BDD Belgium                      |
      | field_core_keywords            | BDD Animal husbandry and welfare |
      | field_proj_funding_source_list | Private funds                    |
      | language                       | und                              |
    And I am viewing a "project" in "published" status:
      | title                          | BDD Digitisation Project 4 |
      | field_proj_geographical_area   | BDD Denmark                |
      | field_core_keywords            | BDD Digitisation           |
      | field_proj_funding_source_list | Other EU research funds    |
      | language                       | und                        |
    And I am viewing a "project" in "published" status:
      | title                          | BDD Digitisation Project 5       |
      | field_proj_geographical_area   | BDD Belgium                      |
      | field_core_keywords            | BDD Animal husbandry and welfare |
      | field_proj_funding_source_list | Other EU research funds          |
      | language                       | und                              |
    And I am viewing a "project" in "published" status:
      | title                          | BDD Digitisation Project 6 |
      | field_proj_geographical_area   | BDD Denmark                |
      | field_core_keywords            | BDD Digitisation           |
      | field_proj_funding_source_list | Other EU research funds    |
      | language                       | und                        |
    # Flag Projects for Digitisation.
    When I am at "admin/content/digitisation-toolbox/projects"
    And I fill in "Title" with "BDD Digitisation Project"
    And I press "Apply"
    And I click "Add to Digitisation toolbox" in the "BDD Digitisation Project 1" row
    And I click "Add to Digitisation toolbox" in the "BDD Digitisation Project 2" row
    And I click "Add to Digitisation toolbox" in the "BDD Digitisation Project 3" row
    And I click "Add to Digitisation toolbox" in the "BDD Digitisation Project 4" row
    And I click "Add to Digitisation toolbox" in the "BDD Digitisation Project 5" row
    And I click "Add to Digitisation toolbox" in the "BDD Digitisation Project 6" row

      # Check that the "View all projects" link in the Digit. home block brings to the Digitisation Projects search page.
    Given I am an anonymous user
    When I am on "digitising-agriculture"
    And I click "View all projects" in the "content_top_left" region
    Then I should see the heading "Digitising Agriculture Projects"

      # Test "Digitisation Projects" search view filters.
    When I am on "digitising-agriculture/projects"
      # Test Fulltext search fields.
    And I fill in "Fulltext search" with "BDD,1"
    And I press the "edit-submit-agri-digitization-toolbox-projects-indexed-search" button
    Then I should see "BDD Digitisation Project 1" in the "content" region
    And I should not see "BDD Digitisation Project 2" in the "content" region
    And I press the "Reset" button
    And I fill in "Fulltext search" with "BDD,auctor risus"
    And I press the "edit-submit-agri-digitization-toolbox-projects-indexed-search" button
    Then I should see "BDD Digitisation Project 1" in the "content" region
    And I should not see "BDD Digitisation Project 2" in the "content" region
    And I press the "Reset" button
    And I fill in "Fulltext search" with "BDD,nisi lacus"
    And I press the "edit-submit-agri-digitization-toolbox-projects-indexed-search" button
    Then I should see "BDD Digitisation Project 2" in the "content" region
    And I should not see "BDD Digitisation Project 1" in the "content" region
    And I press the "Reset" button
    And I fill in "Fulltext search" with "BDD,donec fringilla"
    And I press the "edit-submit-agri-digitization-toolbox-projects-indexed-search" button
    Then I should see "BDD Digitisation Project 1" in the "content" region
    And I should not see "BDD Digitisation Project 2" in the "content" region
    And I press the "Reset" button
    And I fill in "Fulltext search" with "BDD,ut inceptos"
    And I press the "edit-submit-agri-digitization-toolbox-projects-indexed-search" button
    Then I should see "BDD Digitisation Project 2" in the "content" region
    And I should not see "BDD Digitisation Project 1" in the "content" region
    And I press the "Reset" button
    And I select "BDD Animal husbandry and welfare" from "Keywords"
    And I press the "edit-submit-agri-digitization-toolbox-projects-indexed-search" button
    Then I should see "BDD Digitisation Project 5"
    And I should not see "BDD Digitisation Project 6"
    And I press the "Reset" button
    And I select "Private funds" from "Main funding source"
    And I press the "edit-submit-agri-digitization-toolbox-projects-indexed-search" button
    Then I should see "BDD Digitisation Project 3"
    And I should not see "BDD Digitisation Project 6"
    And I press the "Reset" button
    And I select "BDD Denmark" from "Geographical location"
    And I press the "edit-submit-agri-digitization-toolbox-projects-indexed-search" button
    Then I should see "BDD Digitisation Project 2"
    And I should not see "BDD Digitisation Project 1"
    And I press the "Reset" button

  @anonymous @digitisation-frontend @search_api_node
  Scenario: As Anonymous I want to view the list of Publications flagged by Digitisation and use filters to search for them.
    Given I am logged in as a user with the "administrator" role
    And "core_geographical_area" terms:
      | name        |
      | BDD Belgium |
    And "tags" terms:
      | name                               |
      | BDD Digitisation                   |
      | BDD Agricultural production system |
      | BDD Animal husbandry and welfare   |
    And I am viewing a "publication" in "published" status:
      | title               | BDD Digitisation Publication 1 |
      | body                | Lorem ipsum dolor sit amet     |
      | field_core_keywords | BDD Digitisation               |
      | language            | und                            |
    And I am viewing a "publication" in "published" status:
      | title               | BDD Digitisation Publication 2          |
      | body                | Lorem ipsum habitasse quisque fermentum |
      | field_core_keywords | BDD Agricultural production system      |
      | language            | und                                     |
    And I am viewing a "publication" in "published" status:
      | title               | BDD Digitisation Publication 3            |
      | body                | Lorem ipsum libero lacus condimentum erat |
      | field_core_keywords | BDD Animal husbandry and welfare          |
      | language            | und                                       |
    And I am viewing a "publication" in "published" status:
      | title               | BDD Digitisation Publication 4           |
      | body                | Lorem ipsum augue dolor tempus habitasse |
      | field_core_keywords | BDD Animal husbandry and welfare         |
      | language            | und                                      |
    And I am viewing a "publication" in "published" status:
      | title               | BDD Digitisation Publication 5 |
      | body                | Lorem ipsum nisl lectus        |
      | field_core_keywords | BDD Digitisation               |
      | language            | und                            |
    And I am viewing a "publication" in "published" status:
      | title               | BDD Digitisation Publication 6              |
      | body                | Lorem ipsum curabitur ut tortor fusce felis |
      | field_core_keywords | BDD Agricultural production system          |
      | language            | und                                         |
    And I am viewing a "publication" in "published" status:
      | title               | BDD Digitisation Publication 7     |
      | body                | Lorem ipsum neque lorem rhoncus    |
      | field_core_keywords | BDD Agricultural production system |
      | language            | und                                |
    And I am viewing a "publication" in "published" status:
      | title               | BDD Digitisation Publication 8             |
      | body                | Lorem ipsum bibendum imperdiet condimentum |
      | field_core_keywords | BDD Digitisation                           |
      | language            | und                                        |
    # Flag Publications for Digitisation.
    When I am at "admin/content/digitisation-toolbox"
    And I click "Add to Digitisation toolbox" in the "BDD Digitisation Publication 1" row
    And I click "Add to Digitisation toolbox" in the "BDD Digitisation Publication 2" row
    And I click "Add to Digitisation toolbox" in the "BDD Digitisation Publication 3" row
    And I click "Add to Digitisation toolbox" in the "BDD Digitisation Publication 4" row
    And I click "Add to Digitisation toolbox" in the "BDD Digitisation Publication 5" row
    And I click "Add to Digitisation toolbox" in the "BDD Digitisation Publication 6" row
    And I click "Add to Digitisation toolbox" in the "BDD Digitisation Publication 7" row
    And I click "Add to Digitisation toolbox" in the "BDD Digitisation Publication 8" row

    # Check that the "View more" link in the Digit. home block brings to the Digitisation Publications search page.
    Given I am an anonymous user
    When I am on "digitising-agriculture"
    And I click "View more" in the "sidebar_right" region
    And I fill in "Fulltext search" with "BDD"
    And I press the "edit-submit-publications-search" button
    Then I should see the heading "Digitising Agriculture Publications"
    And I should see the heading "BDD Digitisation Publication 1" in the "content" region
    And I should see the heading "BDD Digitisation Publication 2" in the "content" region
    And I should see the heading "BDD Digitisation Publication 3" in the "content" region
    And I should see the heading "BDD Digitisation Publication 4" in the "content" region
    And I should see the heading "BDD Digitisation Publication 5" in the "content" region
    And I should see the heading "BDD Digitisation Publication 6" in the "content" region
    And I should see the heading "BDD Digitisation Publication 7" in the "content" region
    And I should see the heading "BDD Digitisation Publication 8" in the "content" region

    # Test "Digitisation Publications" search view filters.
    When I am on "digitising-agriculture/publications"
    And I fill in "Fulltext search" with "BDD,1"
    And I press the "edit-submit-publications-search" button
    Then I should see "BDD Digitisation Publication 1" in the "content" region
    And I should not see "BDD Digitisation Publication 2" in the "content" region
    And I press the "Reset" button
    And I fill in "Fulltext search" with "BDD,quisque fermentum"
    And I press the "edit-submit-publications-search" button
    Then I should see "BDD Digitisation Publication 2" in the "content" region
    And I should not see "BDD Digitisation Publication 3" in the "content" region
    And I press the "Reset" button
    And I select "BDD Animal husbandry and welfare" from "Keywords"
    And I press the "edit-submit-publications-search" button
    Then I should see "BDD Digitisation Publication 4"
    And I should not see "BDD Digitisation Project 5"

  @javascript @search_api_node @title_fallback
  Scenario: As user I should see the english title instead of the native language one
  in every projects block or list page.
    Given I am logged in as a user with the "administrator" role
    And "core_geographical_area" terms:
      | name      |
      | BDD Italy |
    And "tags" terms:
      | name            |
      | BDD Digital HUB |
    # Create a Digitisation toolbox page content with menu link.
    And I am at "node/add/digitisation-toolbox"
    Then I should see "Create Digitisation Toolbox page"
    When I fill in "Title" with "BDD Projects Titles"
    And I click "Menu settings"
    And I check the box "Provide a menu link"
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I press the "Save" button
    And I am at "node/add/digitisation-toolbox"
    Then I should see "Create Digitisation Toolbox page"
    When I fill in "Title" with "BDD Digital HUB"
    And I set the chosen element "edit-field-core-keywords-und" to "BDD Digital HUB"
    And I click "Menu settings"
    And I check the box "Provide a menu link"
    And I select "-- BDD Projects Titles" from "Parent item"
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I press the "Save" button
    # Create a published Project.
    And I am viewing a "project" content in "published" status:
      | title                        | BDD Project native lang |
      | field_proj_title_eng         | BDD Project eng         |
      | language                     | und                     |
      | field_proj_geographical_area | BDD Italy               |
      | field_core_keywords          | BDD Digital HUB         |
    And I click "Add to Digitisation toolbox"
    And I wait for AJAX to finish
    And I am viewing a "project" content in "published" status:
      | title                        | BDD Project title fallback |
      | language                     | und                        |
      | field_proj_geographical_area | BDD Italy                  |
      | field_core_keywords          | BDD Digital HUB            |
    And I click "Add to Digitisation toolbox"
    And I wait for AJAX to finish
    When I am at "digitising-agriculture"
    Then I should see the link "BDD Project eng" in the "content_top_left"
    But I should not see the link "BDD Project native lang" in the "content_top_left"
    And I should see the link "BDD Project title fallback" in the "content_top_left"
    When I am at "digitising-agriculture/projects"
    Then I should see the link "sort by Published on" in the "content"
    Then I should see the link "sort by Title" in the "content"
    And I should see the link "sort by Project type" in the "content"
    And I should see the link "BDD Project eng" in the "content"
    But I should not see the link "BDD Project native lang" in the "content"
    And I should see the link "BDD Project title fallback" in the "content"
    When I click "Digitising Agriculture"
    And I click "BDD Projects Titles"
    Then I click "BDD Digital HUB"
    Then I should see the link "BDD Project eng" in the "content_top_left"
    And I should see the link "BDD Project title fallback" in the "content_top_left"
    But I should not see the link "BDD Project native lang" in the "content_top_left"
