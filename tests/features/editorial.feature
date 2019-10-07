@api
Feature: Test editorial features of the website

  @workbench
  # Workbench moderation
  Scenario: Check if Workbench Moderation is enabled for contributor role
    Given I am logged in as a user with the "contributor" role
    And I am on "/user"
    Then I should see the link "My workbench"
    When I follow "My workbench"
    Then I should see "My Edits"

  @workbench
  # Check enabled/disabled content types for contributor role
  Scenario: Check node creation permissions for contributor role
    Given I am logged in as a user with the "contributor" role
    When I am on "admin/workbench/create"
    # Disabled content types for contributors
    Then I should not see the link "Collaborative area"
    And I should not see the link "Article"
    And I should not see the link "Community"
    And I should not see the link "Poll"
    And I should not see the link "Webform"
    # Enabled content types for contributors
    But I should see the link "Basic page"
    And I should see the link "Event"
    And I should see the link "Needs for research from practice"
    And I should see the link "News"
    And I should see the link "Online resource"
    And I should see the link "Press clipping"
    And I should see the link "Press Release"
    And I should see the link "Project"
    And I should see the link "Project ideas"
    And I should see the link "Publication"
    And I should see the link "Simplenews newsletter"

  @workbench
  # Workbench moderation
  Scenario: Check if Workbench is enabled  for editor role
    Given I am logged in as a user with the "editor" role
    And I am on "/user"
    Then I should see the link "My workbench"
    When I follow "My workbench"
    Then I should see "My Edits"

  @workbench
  # Check enabled/disabled content types for editor role
  Scenario: Check node creation permissions for editor role
    Given I am logged in as a user with the "editor" role
    When I am on "/admin/workbench/create"
    # More enabled content types for editor
    Then I should see the link "Administration"
    And I should see the link "Collaborative area"
    And I should see the link "Gallery"
    And I should see the link "Funding opportunities"
    And I should see the link "News"
    And I should see the link "Poll"
    And I should see the link "Webform"

  Scenario: Check new image fields in Basic pages node add form
    Given I am logged in as a user with the "editor" role
    And I am on "node/add/page"
    Then I should see "Images"
    And I should see "Image (top)"
    And I should see "Image (left)"
    And I should see "Image (right)"
    And I should see "Bulk image upload"

  @required_fields
  Scenario: Check required fields in various node add forms
    Given I am logged in as a user with the "administrator" role
    # Administration
    When I am at "node/add/administration"
    And I press the "Save" button
    Then I should see the following error message:
      | Administration name field is required. |
    # Basic page
    When I am at "node/add/page"
    And I press the "Save" button
    Then I should see the following error message:
      | error messages              |
      | Title field is required.    |
      | Keywords field is required. |
    # Collaborative area
    When I am at "node/add/collaborative-area"
    And I press the "Save" button
    Then I should see the following error message:
      | error messages                             |
      | Collaborative area name field is required. |
      | Description field is required.             |
      | Keywords field is required.                |
      | Active field is required.                  |
    # Event
    When I am at "node/add/event"
    And I press the "Save" button
    Then I should see the following error message:
      | error messages                   |
      | Title field is required.         |
      | Location field is required.      |
      | Venue Address field is required. |
      | Type of event field is required. |
    # Funding opportunities
    When I am at "node/add/funding-opportunities"
    And I press the "Save" button
    Then I should see the following error message:
      | error messages                                                       |
      | Title field is required.                                             |
      | Eligibility criteria field is required.                              |
      | Contact e-mail field is required.                                    |
      | Keywords field is required.                                          |
      | Organization/Institution name (original language) field is required. |
      | Agricultural sectors field is required.                              |
      | Type of funding field is required.                                   |
    # Gallery
    When I am at "node/add/gallery"
    And I press the "Save" button
    Then I should see the following error message:
      | Gallery field is required. |
    # Needs for research from practice
    When I am at "node/add/needs-for-research-from-practice"
    Then I should see "Spoken languages"
    And I should see "By clicking either of the options you agree to show your name on the EIP-AGRI website and allow other registered users to contact you. Your contact email will not be disclosed"
    When I press the "Save" button
    Then I should see the following error message:
      | error messages                         |
      | Title field is required.               |
      | This is the problem field is required. |
      | Geographical scope field is required.  |
      | Keywords field is required.            |
      | Language field is required.            |
    # Online resource
    When I am at "node/add/online-resource"
    Then I should see "Language of the website"
    When I press the "Save" button
    Then I should see the following error message:
      | error messages                               |
      | Title (Original Language) field is required. |
      | Keywords field is required.                  |
      | URL field is required.                       |
      | Title (english) field is required.           |
    # Press clipping
    When I am at "node/add/press-clipping"
    And I press the "Save" button
    Then I should see the following error message:
      | error messages                        |
      | Title field is required.              |
      | Keywords field is required.           |
      | Information source field is required. |
    # Press release
    When I am at "node/add/press-release"
    And I press the "Save" button
    Then I should see the following error message:
      | error messages              |
      | Title field is required.    |
      | Keywords field is required. |
    # Project ideas
    When I am at "node/add/project-ideas"
    Then I should see "Spoken languages"
    # The following field has no access set via code, but it's somehow visible.
    # But I should not see "Deadline for contact"
    When I press the "Save" button
    Then I should see the following error message:
      | error messages                                           |
      | Title (native language) field is required.               |
      | Description field is required.                           |
      | Contact E-mail field is required.                        |
      | Geographical scope field is required.                    |
      | Keywords field is required.                              |
      | Project coordinator is searching for… field is required. |
      | Language field is required.                              |
    # Publication
    When I am at "node/add/publication"
    And I press the "Save" button
    Then I should see the following error message:
      | error messages                                                 |
      | Title (original language) field is required.                   |
      | Geographical scope field is required.                          |
      | Keywords field is required.                                    |
      | Title (in English) field is required.                          |
      | Publication abstract (in original language) field is required. |
      | Author(s) field is required.                                   |
      | Publication type field is required.                            |

  @javascript
  Scenario: Check the conditional fields functionality in some content types.
    Given I am logged in as a user with the "administrator" role
    # Conditional fields in: News.
    Given "tags" terms:
      | name        |
      | BDD Keyword |
    And I am viewing a "news" content in "draft" status:
      | title                        | BDD News                            |
      | field_core_geographical_area | Belgium                             |
      | field_core_keywords          | BDD Keyword                         |
      | field_news_publication_date  | 01-01-2019 09:00:00 Europe/Brussels |
    When I click "Edit draft"
    And I set the chosen element "Geographical scope" to "Other"
    And I fill in "Specify other location" with "BDD other location"
    And I click "Publishing options"
    And I select "published" from "Moderation state"
    And I press the "Save" button
    And I should see "BDD other location" in the "Geographical scope" row
    And I should see "Publication date:" in the content
    And I should see "Tuesday, 1 January, 2019 - 09:00" in the content

    # Conditional fields in: Funding opportunities.
    Given "agricultural_sectors" terms:
      | name       |
      | BDD Sector |
    And I am viewing a "funding_opportunities" content in "draft" status:
      | title                           | BDD Funding             |
      | field_news_type_of_funding      | Rural Development       |
      | field_core_publication_date     | 01-01-2019 - 31-01-2019 |
      | field_core_agricultural_sectors | BDD Sector              |
      | field_news_geographical_area    | Belgium                 |
      | field_core_keywords             | BDD Keyword             |
    When I click "Edit draft"
    And I click "Text area settings"
    And I click "Disable rich-text"
    And I fill in "Eligibility criteria" with "BDD Eligibility Criteria"
    And I set the chosen element "Geographical scope" to "Other"
    And I fill in "Specify other location" with "BDD other location"
    And I fill in "Contact e-mail" with "userexample@example.com"
    And I fill in "Organization/Institution name (original language)" with "BDD ORG"
    And I fill in "Department (original language)" with "BDD DEP"
    And I fill in "Unit (original language)" with "BDD Unit"
    And I click "Publishing options"
    And I select "published" from "Moderation state"
    And I press the "Save" button
    Then I should see "BDD other location" in the "Geographical scope" row
    And I should see "Tuesday, 1 January, 2019 to Thursday, 31 January, 2019" in the "Opening/closing dates" row
    And I should see "BDD Keyword" in the "Keywords" row
    And I should see "Programme institution"
    And I should see "BDD ORG"
    And I should see "Department (original language)"
    And I should see "BDD DEP"
    And I should see "Unit (original language)"
    And I should see "BDD Unit"

    # Conditional fields in: Needs for research from practice.
    Given I am viewing a "needs_for_research_from_practice" content in "draft" status:
      | title                        | BDD NFRFP                                      |
      | field_core_geographical_area | Belgium                                        |
      | field_core_keywords          | BDD Keyword                                    |
      | field_core_email:email       | bdduser@example.com                            |
      | field_projects_language      | English                                        |
      | field_projects_name          | Mario                                          |
      | field_projects_surname       | Rossi                                          |
      | field_projects_interested_in | Taking part in a project related to this issue |
    When I click "Edit draft"
    And I click "Text area settings"
    And I click "Disable rich-text"
    And I fill in "This is the problem" with "BDD Problem"
    And I set the chosen element "Geographical scope" to "Other"
    And I fill in "Other location" with "BDD other location"
    And I set the chosen element "Spoken languages" to "English"
    And I click "Publishing options"
    And I select "published" from "Moderation state"
    And I press the "Save" button
    Then I should see "BDD other location" in the "Geographical scope" row
    And I should see "Contact person"
    And I should see "Name: Mario"
    And I should see "Surname: Rossi"
    And I should see "Spoken languages: English"
    And I should see the link "Contact person by email"
    When I follow "Contact person by email"
    Then I should see the heading "Email Contact Form"
    And I should see "Your name"
    And I should see "Your e-mail address"
    And I should see "Subject"
    And I should see "Message"
    And I should see the button "Send e-mail" in the "content" region

    # Conditional fields in: Project ideas.
    When I am viewing a "project_ideas" content in "draft" status:
      | title                        | BDD Project Idea |
      | field_projects_language      | English          |
      | field_project_searching      | Lorem ipsum      |
      | field_core_geographical_area | Belgium          |
      | field_core_keywords          | BDD Keyword      |
      | field_projects_outcomes      | BDD Outcomes     |
      | field_projects_outcomes_eng  | BDD Outcomes ENG |
    When I click "Edit draft"
    And I click "Text area settings"
    And I click "Disable rich-text"
    And I fill in "Description" with "BDD Description"
    And I set the chosen element "Geographical scope" to "Other"
    And I fill in "Other location" with "BDD other location"
    And I set the chosen element "Spoken languages" to "English"
    And I fill in "Contact E-mail" with "bdduser@example.com"
    And I click "Publishing options"
    And I select "published" from "Moderation state"
    And I press the "Save" button
    Then I should see "English" in the "Spoken languages" row
    And I should see "bdduser@example.com" in the "Contact E-mail" row