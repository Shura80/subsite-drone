@api @projects
Feature: Test for content type Projects

  Background: Creation of the taxonomy term for a new Project
    Given "tags" terms:
      | name                   |
      | BDD Keyword 1          |
      | BDD Keyword 2          |
      | BDD Additional Keyword |
    And "agricultural_sectors" terms:
      | name                   |
      | BDD agriculture sector |

  @solr
  Scenario: Verify that the privacy policy setting shows or hides the Parnters information according to the
  privacy option set in admin interface.
    Given I am logged in as a user with the "administrator" role
    And "core_geographical_area" terms:
      | name        |
      | BDD Germany |
      | BDD Belgium |

    And I am on "admin/config/agri-project/country-privacy"
    When I check the box "BDD Germany"
    And I uncheck the box "BDD Belgium"
    And I press the "Save configuration" button
    Then I should see the following success messages:
      | The configuration options have been saved. |

    # Hide Partners info
    And I am viewing a "project" content in "published" status:
      | title                           | BDD projects Operational Group                                                               |
      | field_proj_title_eng            | BDD projects Operational Group                                                               |
      | field_projects_language         | Italian                                                                                      |
      | field_proj_project_type         | Operational group                                                                            |
      | field_proj_problems             | BDD Objective                                                                                |
      | field_proj_problems_eng         | BDD Objective eng                                                                            |
      | field_proj_desc                 | BDD Description                                                                              |
      | field_proj_desc_eng             | BDD Description eng                                                                          |
      | field_core_keywords             | BDD Keyword 1                                                                                |
      | field_agri_proj_internal_kwords | BDD Additional Keyword                                                                       |
      | field_proj_geographical_area    | BDD Germany                                                                                  |
      | field_core_agricultural_sectors | BDD agriculture sector                                                                       |
      | field_proj_funding_source_list  | Rural development 2014-2020 for Operational Groups (in the sense of Art 56 of Reg.1305/2013) |

    And I create the following "field_proj_coordinator_fc" field collection
      | field_proj_coord_organization   | BDD coordinator organization   |
      | field_proj_coord_contact_person | BDD coordinator contact person |
      | field_proj_coord_address        | BDD coordinator Street 123     |
      | field_proj_coord_email:email    | bdd-coor@BDD.local             |
      | field_proj_coord_phone          | +39 222 22 22 222              |

    And I create the following "field_proj_partner_fc" field collection
      | field_proj_prtnr_organization   | BDD ORG Example             |
      | field_proj_prtnr_contact_person | BDD ORG Example Responsible |
      | field_proj_prtnr_address        | BDD ORG Place 100           |
      | field_proj_prtnr_email:email    | org-example@example.com     |
      | field_proj_prtnr_phone          | +49 444 44 44 444           |

    And I should see "Operational group" in the "Project type" row
    And I should not see the text "BDD ORG Example"
    And I should not see the text "BDD ORG Example Responsible"
    And I should not see the text "BDD ORG Place 100"
    And I should not see the text "org-example@example.com"
    And I should not see the text "+49 444 44 44 444"

    # Show Partners info
    And I am viewing a "project" content in "published" status:
      | title                           | BDD projects Operational Group                                                               |
      | field_proj_title_eng            | BDD projects Operational Group                                                               |
      | field_projects_language         | Italian                                                                                      |
      | field_proj_project_type         | Operational group                                                                            |
      | field_proj_problems             | BDD Objective                                                                                |
      | field_proj_problems_eng         | BDD Objective eng                                                                            |
      | field_proj_desc                 | BDD Description                                                                              |
      | field_proj_desc_eng             | BDD Description eng                                                                          |
      | field_core_keywords             | BDD Keyword 1                                                                                |
      | field_agri_proj_internal_kwords | BDD Additional Keyword                                                                       |
      | field_proj_geographical_area    | BDD Belgium                                                                                  |
      | field_core_agricultural_sectors | BDD agriculture sector                                                                       |
      | field_proj_funding_source_list  | Rural development 2014-2020 for Operational Groups (in the sense of Art 56 of Reg.1305/2013) |

    And I create the following "field_proj_coordinator_fc" field collection
      | field_proj_coord_organization   | BDD coordinator organization   |
      | field_proj_coord_contact_person | BDD coordinator contact person |
      | field_proj_coord_address        | BDD coordinator Street 123     |
      | field_proj_coord_email:email    | bdd-coor@BDD.local             |
      | field_proj_coord_phone          | +39 222 22 22 222              |

    And I create the following "field_proj_partner_fc" field collection
      | field_proj_prtnr_organization   | BDD partner organization name |
      | field_proj_prtnr_contact_person | BDD partner contact person    |
      | field_proj_prtnr_address        | BDD partner Street 123        |
      | field_proj_prtnr_email:email    | bdd-partner@BDD.local         |
      | field_proj_prtnr_phone          | +32 333 33 33 333             |

    And I should see "Operational group" in the "Project type" row
    And I should see the text "BDD partner organization name"
    And I should see the text "BDD partner contact person"
    And I should see the text "BDD partner Street 123"
    And I should see the text "bdd-partner@BDD.local"
    And I should see the text "+32 333 33 33 333"

    # Hide Partners info
    Given I am an anonymous user
    When I send the "project" to the Solr search index
    And I am on "/search/site/"
    And I fill in "Search" with "ORG+Example"
    And I press the "Search" button
    And I should not see "BDD projects Operational Group" in the "content" region
    And I fill in "Search" with "ORG+Example+Responsible"
    And I press the "Search" button
    And I should not see "BDD projects Operational Group" in the "content" region
    And I fill in "Search" with "ORG+Place+100"
    And I press the "Search" button
    And I should not see "BDD projects Operational Group" in the "content" region
    And I fill in "Search" with "org-example@example.com"
    And I press the "Search" button
    And I should not see "BDD projects Operational Group" in the "content" region
    And I fill in "Search" with "+49+444+44+44+444"
    And I press the "Search" button
    And I should not see "BDD projects Operational Group" in the "content" region

    # Show Partners info
    And I am on "/search/site/"
    And I fill in "Search" with "BDD+partner+organization+name"
    And I press the "Search" button
    And I should see "BDD projects Operational Group" in the "content" region
    And I fill in "Search" with "BDD+partner+contact+person"
    And I press the "Search" button
    And I should see "BDD projects Operational Group" in the "content" region
    And I fill in "Search" with "BDD+partner+Street+123"
    And I press the "Search" button
    And I should see "BDD projects Operational Group" in the "content" region
    And I fill in "Search" with "bdd-partner@BDD.local"
    And I press the "Search" button
    And I should see "BDD projects Operational Group" in the "content" region
    And I fill in "Search" with "+39 333 33 33 333"
    And I press the "Search" button
    And I should see "BDD projects Operational Group" in the "content" region

  @solr @javascript @h2020
  Scenario: As Administrator I can flag a Project to hide Partners information.
  As anonymous, I should see or not Partners information while searching for it,
  according to the flag.

    Given I am an anonymous user
    Given I am viewing a "project" content in "published" status:
      | language                        | und                                               |
      | field_project_puid              | BDD-123-456                                       |
      | title                           | BDD Table ronde H2020                             |
      | field_proj_title_eng            | BDD Table ronde H2020 eng                         |
      | field_projects_language         | English                                           |
      | field_proj_problems             | BDD Objective                                     |
      | field_proj_problems_eng         | BDD Objective eng                                 |
      | field_core_keywords             | BDD Keyword 1                                     |
      | field_core_agricultural_sectors | BDD agriculture sector                            |
      | field_proj_funding_source_list  | Horizon 2020 (EU Research & Innovation programme) |
      | field_proj_contact_e_mail       | bdd-contact@bdd-email.local                       |

    And I create the following "field_proj_coordinator_fc" field collection
      | field_proj_coord_organization   | BDD coordinator organization   |
      | field_proj_coord_contact_person | BDD coordinator contact person |
      | field_proj_coord_address        | BDD coordinator Street 123     |
      | field_proj_coord_email:email    | bdd-coor@BDD.local             |
      | field_proj_coord_phone          | +39 222 22 22 222              |

    And I create the following "field_proj_partner_fc" field collection
      | field_proj_prtnr_organization   | Knights of Justice   |
      | field_proj_prtnr_contact_person | Sir Lancelot         |
      | field_proj_prtnr_address        | Round Table 2        |
      | field_proj_prtnr_email:email    | lancelot@example.com |
      | field_proj_prtnr_phone          | +39 444 44 44 444    |

    Then I should see "BDD Table ronde H2020" in the "content" region
    Then I should see "BDD coordinator organization" in the "content" region
    Then I should see "BDD coordinator contact person" in the "content" region
    And I click "Project partners"
    Then I should see "Knights of Justice" in the "content" region
    Then I should see "Sir Lancelot" in the "content" region
    Then I should see "Round Table 2" in the "content" region
    Then I should see "lancelot@example.com" in the "content" region
    Then I should see "+39 444 44 44 444" in the "content" region
    Then I should not see the link "Hide Project Partners' information"

    # I should be able to find Partners info via Solr page.
    Then I send the "project" to the Solr search index

    When I am on "search/site"
    And I fill in "keys" with "\"BDD Table ronde H2020\""
    And I press the "submit" button
    Then I should see "BDD Table ronde H2020" in the "content" region
    And I fill in "keys" with "\"Knights of Justice\""
    And I press the "submit" button
    Then I should see "BDD Table ronde H2020" in the "content" region
    And I fill in "keys" with "\"Sir Lancelot\""
    And I press the "submit" button
    Then I should see "BDD Table ronde H2020" in the "content" region
    And I fill in "keys" with "\"Round Table 2\""
    And I press the "submit" button
    Then I should see "BDD Table ronde H2020" in the "content" region
    And I fill in "keys" with "lancelot@example.com"
    And I press the "submit" button
    Then I should see "BDD Table ronde H2020" in the "content" region
    And I fill in "keys" with "\"+39 444 44 44 444\""
    And I press the "submit" button
    Then I should see "+39 444 44 44 444" in the "content" region

    Given I am logged in as a user with the "administrator" role
    # First, check that it's flagged.
    When I am at "sfc-projects/manage-projects"
    And I click "Hide Project Partners' information" in the "BDD Table ronde H2020" row

    # Test "Show Project Partners' information" link on Project node view.
    And I click "BDD Table ronde H2020"
    Then I should see the link "Show Project Partners' information"

    Then I send the "project" to the Solr search index

    Given I am an anonymous user
    # I should not be able to find Partners info via Solr page.
    When I am on "search/site"
    And I fill in "keys" with "\"Knights of Justice\""
    And I press the "submit" button
    Then I should not see "BDD Table ronde H2020" in the "content" region
    And I fill in "keys" with "\"Sir Lancelot\""
    And I press the "submit" button
    Then I should not see "BDD Table ronde H2020" in the "content" region
    And I fill in "keys" with "\"Round Table 2\""
    And I press the "submit" button
    Then I should not see "BDD Table ronde H2020" in the "content" region
    And I fill in "keys" with "lancelot@example.com"
    And I press the "submit" button
    Then I should not see "BDD Table ronde H2020" in the "content" region
    And I fill in "keys" with "\"+39 444 44 44 444\""
    And I press the "submit" button
    Then I should not see "+39 444 44 44 444" in the "content" region

    And I fill in "keys" with "\"BDD Table ronde H2020\""
    And I press the "submit" button
    Then I should see "BDD Table ronde H2020" in the "content" region

    And I click "BDD Table ronde H2020"
    Then I should not see an "group-proj-partners" element
    Then I should not see "Knights of Justice" in the "content" region
    Then I should not see "Sir Lancelot" in the "content" region
    Then I should not see "Round Table 2" in the "content" region
    Then I should not see "lancelot@example.com" in the "content" region
    Then I should not see "+39 444 44 44 444" in the "content" region
    Then I should not see the link "Show Project Partners' information"

  @authenticated @required_fields
  Scenario: As authenticated user I can create a new project content
  with some mandatory fields.
    Given I am logged in as an "authenticated user"
    When I am at "node/add/project"
    And I press the "Save" button
    Then I should see the following error message:
      | error messages                                                |
      | Title (native language) field is required.                    |
      | Keywords field is required.                                   |
      | Contact e-mail field is required.                             |
      | Main funding source field is required.                        |
      | Geographical location field is required.                      |
      | Objective of the project (native language) field is required. |
      | Objective of the project (in English) field is required.      |
      | Title (in English) field is required.                         |
      | Language field is required.                                   |

  @search_api_node @title_fallback
  Scenario: As anonymous user I should see the english title instead of the native language one
  in every projects block or list page.
    Given I am viewing a "project" content in "published" status:
      | title                | BDD Title native lang |
      | field_proj_title_eng | BDD Title eng         |
      | language             | und                   |
    Given I am viewing a "project" content in "published" status:
      | title    | BDD Title fallback |
      | language | und                |
    And I am an anonymous user
    And I send site contents to the Search API node index
    When I am at "find-connect/projects"
    Then I should see the link "sort by Published on" in the "content"
    Then I should see the link "sort by Title" in the "content"
    And I should see the link "sort by Project type" in the "content"
    And I should see the link "BDD Title eng" in the "content"
    And I should see the link "BDD Title fallback" in the "content"
    But I should not see the link "BDD Title native lang" in the "content"
