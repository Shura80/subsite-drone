@api @projects
Feature: ENRD Projects

  This feature is aimed at creating the Project content type and its related configurations. Projects are created to
  feed the ENRD Contact Point projects database; any published projects are listed and can be filtered on the Projects list page.

  Background: I want to create new projects
    Given "enrd_countries" terms:
      | name       |
      | BDD Europe |
    And "enrd_countries" terms:
      | name           | parent         |
      | European Union | BDD Europe     |
      | BDD Italy      | European Union |
      | BDD Spain      | European Union |

  @anonymous @clean
  Scenario: As anonymous I can see a subset of project fields in the content page and in the Solr Projects DB list page.
    Given: I am an anonymous user
    # ENRD Rural Development Policy
    And "enrd_rural_development_policy" terms:
      | name         |
      | BDD Priority |

    And I am viewing a "project" content in "published" status:
      | title                              | BDD Custom project                     |
      | language                           | en                                     |
      | created                            | 01-01-2020 8:00                        |
      | field_enrd_prj_headline            | BDD Published Custom Project Headline  |
      | field_enrd_prj_full_proj_summary   | BDD Published Custom Project Summary   |
      | field_enrd_prj_results             | BDD Published Custom Project Results   |
      | field_enrd_prj_program_period      | 2007-2013                              |
      | field_enrd_prj_timeframe           | 01-01-2010 - 01-01-2013                |
      | field_enrd_prj_measure             | M13 Areas with constraints             |
      | field_enrd_prj_focus_area          | 6B Local development                   |
      | field_enrd_prj_funding             | Total budget 1000 EUR                  |
      | field_enrd_prj_promoter            | John Doe                               |
      | field_enrd_prj_contact_person      | John Smith                             |
      | field_enrd_prj_contact_email:email | john.smith@example.com                 |
      | field_enrd_prj_contact_phone_num   | +44 123 45 67 890                      |
      | field_enrd_prj_website             | http://example.com - http:/example.com |
      | field_enrd_prj_keywords            | Forestry                               |
      | field_tax_country                  | BDD Spain                              |
      | field_tax_rural_dev_policy         | BDD Priority                           |

    Then I should see the heading "BDD Custom project"
    And I should see "BDD Published Custom Project Headline" in the ".ds-headline" element

    And I should see "Project summary: BDD Published Custom Project Summary" in the ".ds-main" element
    And I should see "Project results: BDD Published Custom Project Results" in the ".ds-main" element
    And I should see "Post date: 01/01/2020 - 08:00" in the ".ds-main" element

    And I should see "Country: BDD Spain" in the "right sidebar" region
    And I should see "Programming period: 2007-2013" in the "right sidebar" region
    And I should see "Priority: BDD Priority" in the "right sidebar" region
    And I should see "Focus Area: 6B Local development" in the "right sidebar" region
    And I should see "Measure: M13 Areas with constraints" in the "right sidebar" region
    And I should see "Funding: Total budget 1000 EUR" in the "right sidebar" region
    And I should see "Timeframe: 2010 to 2013" in the "right sidebar" region
    And I should see "Project promoter: John Doe" in the "right sidebar" region
    And I should see "Contact Person: John Smith" in the "right sidebar" region
    And I should see the "a" element with the "href" attribute set to "mailto:john.smith@example.com" in the "right sidebar" region
    And I should see "+44 123 45 67 890" in the "right sidebar" region
    And I should see "Website: http://example.com" in the "right sidebar" region
    And I should see the link "http://example.com" in the "right sidebar" region
    And I should see "Keywords: Forestry" in the "right sidebar" region

    Then I send the "project" to the Solr search index
    And I am on "projects-practice"

    When I follow "BDD Spain"
    Then I should see the heading "BDD Custom project"
    And I should see the text "BDD Published Custom Project Headline"
    And I should see the text "Keywords: Forestry"
    And I should see the text "Countries: BDD Spain"

  @admin @editor
  Scenario: As Admin or Editor I can access the DG BUDG projects view and export Projects
    in CSV and XLSX format from the "ENRD Administration" menu.
    Given I am logged in as a user with the "editor" role
    When I am at "admin/enrd/projects"
    Then I should see the heading "DG BUDG projects export"
    When I click "Export"
    Then I should get a "200" HTTP response
    When I am at "admin/enrd/projects"
    And I click "XLSX"
    Then I should get a "200" HTTP response

  @editor @workflow @moderate-all
  Scenario: As editor I want to create a new project as well as edit and moderate a project not created by me.
    Given I am logged in as a user with the "editor" role

    When I click "Create content"
    Then I should see the link "Project"
    And I should be able to edit a "project" content

    When I am viewing a "project" content in "needs_review" status:
      | title | BDD editor Project title |
    And I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Validated" in the "BDD editor Project title" row
    Then I should see the text "Validated" in the "BDD editor Project title" row

  @contributor @workflow @moderate-all
  Scenario: As contributor I cannot either edit a project other than mine or moderate it.
    Given I am logged in as a user with the "contributor" role
    And I should not be able to edit a "project" content

    When I am viewing a "project" content in "draft" status:
      | title | BDD contributor Project title |
    And I go to "admin/workbench"
    And I click "Moderate All"
    Then I should see the link "BDD contributor Project title"
    When I click "Change to Needs Review"
    Then I should get a 403 HTTP response

  @filters @solr @clean
  Scenario: I want to test the projects database exposed filters and apply free-text queries to limit results.
    Given I am an anonymous user
    And "project_key_words" terms:
      | name             |
      | BDD Biodiversity |
      | BDD Cooperation  |
    And "measures" terms:
      | name                      |
      | BDD M02 Advisory services |
      | BDD M03 Quality schemes   |
    And "focus_areas" terms:
      | name                     |
      | BDD 6B Local development |
      | BDD 4B Water management  |

    And I am viewing a "project" content in "published" status:
      | title                             | BDD Published Project     |
      | language                          | en                        |
      | field_enrd_prj_headline           | BDD headlinetext          |
      | field_enrd_prj_full_proj_summary  | BDD summarytext           |
      | field_tax_country                 | BDD Italy                 |
      | field_enrd_prj_keywords           | BDD Biodiversity          |
      | field_enrd_prj_measure            | BDD M02 Advisory services |
      | field_enrd_prj_focus_area         | BDD 4B Water management   |
    And I am viewing a "project" content in "published" status:
      | title                     | BDD Yet another project  |
      | language                  | en                       |
      | field_enrd_prj_results    | BDD resultstext          |
      | field_tax_country         | BDD Spain                |
      | field_enrd_prj_keywords   | BDD Cooperation          |
      | field_enrd_prj_measure    | BDD M03 Quality schemes  |
      | field_enrd_prj_focus_area | BDD 6B Local development |
    When I send the "project" to the Solr search index
    And I go to "projects-practice"

    # Countries filter.
    When I follow "BDD Spain"
    Then I should see the link "BDD Yet another project" in the "content" region
    But I should not see the link "BDD Published Project" in the "content" region
    And I follow "Clear filters"
    # Keywords filter.
    When I follow "BDD Biodiversity"
    Then I should see the link "BDD Published Project" in the "content" region
    But I should not see the link "BDD Yet another project" in the "content" region
    And I follow "Clear filters"

    # I should see the "Advanced search" filters grouping.
    And I should see the text "Advanced search"
    # Focus Area filter.
    When I follow "BDD 4B Water management"
    Then I should see the link "BDD Published Project" in the "content" region
    But I should not see the link "BDD Yet another project" in the "content" region
    # Measure filter.
    When I follow "BDD M02 Advisory services"
    Then I should see the link "BDD Published Project" in the "content" region
    But I should not see the link "BDD Yet another project" in the "content" region
    And I follow "Clear filters"

    # Check that I can search for title, Project summary, Project results and Headline.
    When I fill in "keys" with "Yet another"
    And I press the "Search" button
    Then I should see the link "BDD Yet another project" in the "content" region
    But I should not see the link "BDD Published Project" in the "content" region

    And I go to "projects-practice"
    When I fill in "keys" with "headlinetext"
    And I press the "Search" button
    Then I should see the link "BDD Published Project" in the "content" region
    But I should not see the link "BDD Yet another project" in the "content" region

    And I go to "projects-practice"
    When I fill in "keys" with "summarytext"
    And I press the "Search" button
    Then I should see the link "BDD Published Project" in the "content" region
    But I should not see the link "BDD Yet another project" in the "content" region

    And I go to "projects-practice"
    When I fill in "keys" with "resultstext"
    And I press the "Search" button
    Then I should see the link "BDD Yet another project" in the "content" region
    But I should not see the link "BDD Published Project" in the "content" region
