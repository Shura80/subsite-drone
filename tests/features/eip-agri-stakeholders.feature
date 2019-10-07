@api @stakeholders
Feature: Test the EIP-AGRI stakeholders area

  Scenario: Check if Stakeholder taxonomy exists and that all terms exist.
    # Stakeholders vocabulary and terms
    Given I am logged in as a user with the "administrator" role
    And I am at "admin/structure/taxonomy"
    Then I should see "Stakeholders"
    When I am on "admin/structure/taxonomy/core_stakeholders"
    Then I should see the link "Operational Groups"
    And I should see the link "Farmers"
    And I should see the link "Farm Advisers"
    And I should see the link "Managing Authorities"
    And I should see the link "National Support Groups"
    And I should see the link "Researchers"
    And I should see the link "Agribusiness"
    And I should see the link "Thematic Networks"
    And I should see the link "Multi-Actor Projects"

  Scenario: Test "EIP-AGRI Projects" section.
    Given "core_stakeholders" terms:
      | name            | field_core_stakeholders_active |
      | BDD Stakeholder | Active                         |
    And "core_geographical_area" terms:
      | name        |
      | BDD Germany |
      | BDD Belgium |
    # Create a published Basic Page.
    And I am viewing a "page" content in "published" status:
      | title                          | BDD page published |
      | field_core_stakeholders        | BDD Stakeholder    |
      | language                       | und                |
      | field_stakeholders_short_title | BDD short title    |
    # Create a published Publication.
    And I am viewing a "publication" content in "published" status:
      | title                   | BDD publication published |
      | language                | und                       |
      | field_core_stakeholders | BDD Stakeholder           |
    # Create a published Project "Operational Group".
    And I am viewing a "project" content in "published" status:
      | title                          | BDD projects Operational Group                                                               |
      | language                       | und                                                                                          |
      | field_proj_title_eng           | BDD projects Operational Group                                                               |
      | field_projects_language        | Italian                                                                                      |
      | field_proj_project_type        | Operational group                                                                            |
      | field_proj_geographical_area   | BDD Germany                                                                                  |
      | field_proj_funding_source_list | Rural development 2014-2020 for Operational Groups (in the sense of Art 56 of Reg.1305/2013) |
    # Create a published Project "H2020".
    And I am viewing a "project" content in "published" status:
      | title                          | BDD projects H2020                                |
      | language                       | und                                               |
      | field_proj_title_eng           | BDD projects H2020                                |
      | field_projects_language        | Italian                                           |
      | field_proj_sfc_identification  | Thematic network                                  |
      | field_proj_geographical_area   | BDD Belgium                                       |
      | field_proj_funding_source_list | Horizon 2020 (EU Research & Innovation programme) |

    # View block in main page.
    When I am on "/eip-agri-projects/"
    Then I should see 'Discover Operational Group Projects' in the "content" region
    And I should see "Relevant EIP-AGRI documents" in the "content_first" region
    And I should see "BDD publication published" in the "content_first" region
    And I should see "More about..." in the "content_second" region
    And I should see "BDD short title" in the "content_second" region
    And I should see "Latest Operational Groups" in the "content_right" region
    And I should see "BDD projects Operational Group" in the "content_right" region
    And I should see "Latest Horizon 2020 projects" in the "content_third" region
    And I should see "BDD projects H2020" in the "content_third" region
    When I click "view more"
    Then I should see "BDD publication published" in the "content" region

  @search_api_node @title_fallback
  Scenario: As anonymous user I should see the english title instead of the native language one
  in every projects block or list page.
    Given "core_geographical_area" terms:
      | name      |
      | BDD Italy |
    # Create published Projects "Operational Group".
    And I am viewing a "project" content in "published" status:
      | title                          | BDD Operational native lang                                                                  |
      | field_proj_title_eng           | BDD Operational eng                                                                          |
      | language                       | und                                                                                          |
      | field_proj_geographical_area   | BDD Italy                                                                                    |
      | field_proj_project_type        | Operational group                                                                            |
      | field_proj_funding_source_list | Rural development 2014-2020 for Operational Groups (in the sense of Art 56 of Reg.1305/2013) |
    # Operational group with title fallback
    And I am viewing a "project" content in "published" status:
      | title                          | BDD Operational title fallback                                                               |
      | language                       | und                                                                                          |
      | field_proj_geographical_area   | BDD Italy                                                                                    |
      | field_proj_project_type        | Operational group                                                                            |
      | field_proj_funding_source_list | Rural development 2014-2020 for Operational Groups (in the sense of Art 56 of Reg.1305/2013) |
    # Create published Projects "H2020".
    And I am viewing a "project" content in "published" status:
      | title                          | BDD H2020 native lang                             |
      | field_proj_title_eng           | BDD H2020 eng                                     |
      | language                       | und                                               |
      | field_proj_geographical_area   | BDD Italy                                         |
      | field_proj_sfc_identification  | Thematic network                                  |
      | field_proj_funding_source_list | Horizon 2020 (EU Research & Innovation programme) |
      | created                        | now -4 minutes                                    |
    # H2020 with title fallback.
    And I am viewing a "project" content in "published" status:
      | title                          | BDD H2020 title fallback                          |
      | language                       | und                                               |
      | field_proj_geographical_area   | BDD Italy                                         |
      | field_proj_sfc_identification  | Thematic network                                  |
      | field_proj_funding_source_list | Horizon 2020 (EU Research & Innovation programme) |
      | created                        | now -3 minutes                                    |
    # Create published Projects "Multi-actor".
    And I am viewing a "project" content in "published" status:
      | title                          | BDD H2020 Multi-actor native-lang                 |
      | field_proj_title_eng           | BDD H2020 Multi-actor eng                         |
      | language                       | und                                               |
      | field_proj_geographical_area   | BDD Italy                                         |
      | field_proj_sfc_identification  | Multi-actor project                               |
      | field_proj_funding_source_list | Horizon 2020 (EU Research & Innovation programme) |
      | created                        | now -2 minutes                                     |
    # Multi-actor with title fallback.
    And I am viewing a "project" content in "published" status:
      | title                          | BDD H2020 Multi-actor title fallback              |
      | language                       | und                                               |
      | field_proj_geographical_area   | BDD Italy                                         |
      | field_proj_sfc_identification  | Multi-actor project                               |
      | field_proj_funding_source_list | Horizon 2020 (EU Research & Innovation programme) |
      | created                        | now -1 minute                                    |
    When I am at "eip-agri-projects"
    And I send site contents to the Search API node index
    # EIP-AGRI Projects home blocks.
    # Operational groups.
    Then I should see the link "BDD Operational eng" in the "content_right"
    And I should see the link "BDD Operational title fallback" in the "content_right"
    But I should not see the link "BDD Operational native lang" in the "content_right"
    # Thematic networks / "Multi-actor" projects.
    And I should see the link "BDD H2020 Multi-actor title fallback" in the "content_third"
    And I should see the link "BDD H2020 Multi-actor eng" in the "content_third"
    And I should see the link "BDD H2020 title fallback" in the "content_third"
    But I should not see the link "BDD H2020 Multi-actor native-lang" in the "content_third"
    # EIP-AGRI Projects views.
    # Operational groups.
    When I am at "eip-agri-projects/projects/operational-groups"
    Then I should see the link "sort by Published on"
    And I should see the link "sort by Title"
    And I should see the link "BDD Operational eng" in the "content"
    And I should see the link "BDD Operational title fallback" in the "content"
    But I should not see the link "BDD Operational native lang" in the "content"
    # Thematic networks.
    When I am at "eip-agri-projects/projects/thematic-networks"
    Then I should see the link "sort by Published on"
    Then I should see the link "sort by Title"
    And I should see the link "BDD H2020 eng" in the "content"
    And I should see the link "BDD H2020 title fallback" in the "content"
    But I should not see the link "BDD H2020 native lang" in the "content"
    # "Multi-actor" projects.
    When I am at "eip-agri-projects/projects/multi-actor-projects"
    Then I should see the link "sort by Published on"
    Then I should see the link "sort by Title"
    And I should see the link "BDD H2020 Multi-actor title fallback" in the "content"
    And I should see the link "BDD H2020 Multi-actor eng" in the "content"
    But I should not see the link "BDD H2020 Multi-actor native lang" in the "content"
