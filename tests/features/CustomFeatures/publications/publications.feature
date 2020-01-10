@api @publications
Feature: ENRD Publications

  This feature is aimed at testing the Evaluation Publication and the Publication content types and their related configurations.
  Evaluation publications are created in order to feed the ENRD Evaluation Helpdesk's eLibrary, while Publications are created
  in order to feed the general website Publications eLibrary. Both published Evaluation publications and Publications are
  listed and can be filtered by applying facet filters on the related Apache Solr search page.

  @anonymous @evaluation @solr @clean
  Scenario: As Anonymous I can see a subset of Evaluation Publication's fields both on its published page and on the Solr eLibrary page.
    Given I am an anonymous user
    And "tags" terms:
      | name      |
      | BDD Tag 1 |
    And "enrd_evaluation_content_type" terms:
      | name           |
      | BDD Guidelines |
    And "enrd_evaluation_theme" terms:
      | name               |
      | BDD NRN Evaluation |
    And "enrd_evaluation_type" terms:
      | name                             |
      | BDD Ex Ante Evaluation 2014-2020 |
    And "enrd_programming_period" terms:
      | name          |
      | BDD 2007-2013 |
    And "enrd_languages" terms:
      | name        |
      | BDD Spanish |

    And I am viewing a "publication_ehd" content in "published" status:
      | title                                | BDD Custom Evaluation Publication           |
      | created                              | 01-01-2017 8:00                             |
      | language                             | en                                          |
      | field_enrd_publ_ehd_content_type     | BDD Guidelines                              |
      | field_enrd_publ_ehd_abstract         | BDD Published Custom Evaluation Abstract    |
      | field_enrd_publ_ehd_description      | BDD Published Custom Evaluation Description |
      | field_enrd_publ_ehd_public_date      | 01-04-2018                                  |
      | field_enrd_publ_ehd_last_updated     | 13-04-2019                                  |
      | field_enrd_publ_ehd_history          | BDD Publications History notes              |
      | field_enrd_publ_ehd_pages            | 100                                         |
      | field_enrd_publ_ehd_author           | BDD William Shakespeare                     |
      | field_enrd_publ_ehd_editor           | BDD Editor 1 BDD Editor 2 BDD Editor 3      |
      | field_tax_country                    | Ireland                                     |
      | field_tags                           | BDD Tag 1                                   |
      | field_enrd_publ_ehd_rdp              | IE-National                                 |
      | field_tax_languages                  | BDD Spanish                                 |
      | field_enrd_publ_ehd_progr_period     | BDD 2007-2013                               |
      | field_enrd_publ_ehd_eval_theme       | BDD NRN Evaluation                          |
      | field_enrd_publ_ehd_eval_type        | BDD Ex Ante Evaluation 2014-2020            |
      | field_enrd_publ_ehd_further_info     | http://example.com - http://example.com     |
      | field_enrd_publ_ehd_contact:email    | john.doe@example.com                        |
      | field_enrd_publ_ehd_cite_this_public | Example Title - http://example.com          |

    Then I should see the heading "BDD Custom Evaluation Publication"
    And I should see "BDD Published Custom Evaluation Description" in the ".ds-abstract" element
    And I should see "Publication date: April, 2018" in the ".ds-thumb" element
    And I should see "Last updated: 13 April 2019" in the ".ds-metadata" element
    And I should see "Pages: 100" in the ".ds-metadata" element
    And I should see "Author(s): BDD William Shakespeare" in the ".ds-metadata" element
    And I should see "Editor(s): BDD Editor 1 BDD Editor 2 BDD Editor 3" in the ".ds-metadata" element
    And I should see "Country(ies): Ireland" in the ".ds-metadata" element
    And I should see "Keywords: BDD Tag 1" in the ".ds-metadata" element
    And I should see "RDP: IE-National" in the ".ds-metadata" element
    And I should see "Content type: BDD Guidelines" in the ".ds-metadata" element
    And I should see "Languages: BDD Spanish" in the ".ds-metadata" element
    And I should see "Programming period: BDD 2007-2013" in the ".ds-metadata" element
    And I should see "Evaluation Theme: BDD NRN Evaluation" in the ".ds-metadata" element
    And I should see "Evaluation Type: BDD Ex Ante Evaluation 2014-2020" in the ".ds-metadata" element
    And I should see "Further information: http://example.com" in the ".ds-metadata" element
    And I should see "john.doe@example.com" in the ".ds-metadata" element
    When I click "Full update history"
    Then I should see "BDD Publications History notes" in the ".ds-metadata" element

    And I send the "publication_ehd" to the Solr search index

    When I am on "evaluation/publications"
    Then I should see the heading "BDD Custom Evaluation Publication"
    And I should see the text "BDD Published Custom Evaluation Abstract"
    And I should see the text "Publication date: April, 2018"
    And I should see the text "Evaluation Type: BDD Ex Ante Evaluation 2014-2020"
    And I should see the text "Author(s): BDD William Shakespeare"

  @anonymous
  Scenario: Check that the filter to obfuscate the email from spam-bots is active.
    Given I am an anonymous user
    And I am viewing a "publication_ehd" content in "published" status:
      | title                                | BDD Email Filter Evaluation Publication     |
      | created                              | 01-01-2017 8:00                             |
      | language                             | en                                          |
      | field_enrd_publ_ehd_contact:email    | john.doe@example.com                        |

    Then I should see the "a" element with the "href" attribute set to "mailto:john.doe@example.com" in the "content" region

  @evaluation @wip
  Scenario: As Anonymous I want to download the Evaluation Publication file provided in Croatian.
    # FFR: In order to work, this scenario should be included in the scenario where content has already been created,
    # otherwise the node wouldn't be saved.
    Given I am logged in as a user with the "administrator" role
    And I am at "evaluation/publications/bdd-custom-evaluation-publication"
    And I click "New draft"
    And I select "Croatian" from "File Language"
    And I attach the file "bdd-file.pdf" to "media[field_enrd_publ_ehd_file_und_0_field_enrd_publ_ehd_files_und_0]"
    And I press the "field_enrd_publ_ehd_file_und_0_field_enrd_publ_ehd_files_und_0_upload_button" button
    And I click the "<string>" link in the "<string>" modal dialog from the "<string>" WYSIWYG editor
    And I attach the file "bdd-image.jpg" to "Title page image"
    And I press the "field_enrd_publ_ehd_title_image_und_0_upload_button" button
    And I select "Published" from "Moderation state"
    And I press the "Save" button

    Given I am an anonymous user
    And I am at "evaluation/publications/bdd-custom-evaluation-publication"
    Then I should see the link "HR"

  @evaluation_helpdesk @evaluation
  Scenario: As Evaluation Helpdesk I want to create and edit an Evaluation Publication.
    Given I am logged in as a user with the "evaluation helpdesk" role
    And I should be able to edit a "publication_ehd" content

  @editor @evaluation @workflow @moderate-all
  Scenario: As Editor I cannot create or edit an Evaluation Publication but I can moderate it.
    Given I am logged in as a user with the "editor" role
    Then I should not be able to edit a "publication_ehd" content

    Given I am logged in as a user with the "editor, evaluation helpdesk" roles
    When I am viewing a "publication_ehd" content in "needs_review" status:
      | title | BDD editor Evaluation Publication title |
    And I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Validated" in the "BDD editor Evaluation Publication title" row
    Then I should see the text "Validated" in the "BDD editor Evaluation Publication title" row

  @contributor @evaluation @workflow @moderate-all
  Scenario: As contributor I cannot create or edit an Evaluation Publication but I can moderate it.
    Given I am logged in as a user with the "contributor" role
    Then I should not be able to edit a "publication_ehd" content

    Given I am logged in as a user with the "contributor, evaluation helpdesk" roles
    When I am viewing a "publication_ehd" content in "draft" status:
      | title | BDD contributor Evaluation Publication title |
    And I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Needs Review" in the "BDD contributor Evaluation Publication title" row
    Then I should see "Needs Review" in the "BDD contributor Evaluation Publication title" row

  @filters @evaluation @solr @clean
  Scenario: As Anonymous I want to use the Evaluation eLibrary's faceted filters to limit results.
    Given I am an anonymous user
    And "enrd_evaluation_content_type" terms:
      | name           |
      | BDD Reports    |
      | BDD Glossaries |
    And "enrd_evaluation_type" terms:
      | name                              |
      | BDD Mid-term Evaluation 2007-2013 |
      | BDD Ex Ante Evaluation 2014-2020  |
    And "enrd_evaluation_theme" terms:
      | name                       |
      | BDD Environmental impacts  |
      | BDD LEADER-CLLD Evaluation |
    Given "enrd_countries" terms:
      | name   |
      | Europe |
    And "enrd_countries" terms:
      | name           | parent         |
      | European Union | Europe         |
      | BDD Ireland    | European Union |
      | BDD Germany    | European Union |

    And I am viewing an "publication_ehd" content in "published" status:
      | title                            | BDD Published Evaluation Publication |
      | language                         | en                                   |
      | field_tax_country                | BDD Ireland                          |
      | field_enrd_publ_ehd_rdp          | DE-Bayern                            |
      | field_enrd_publ_ehd_content_type | BDD Reports                          |
      | field_enrd_publ_ehd_eval_type    | BDD Mid-term Evaluation 2007-2013    |
      | field_enrd_publ_ehd_eval_theme   | BDD Environmental impacts            |
    And I am viewing an "publication_ehd" content in "published" status:
      | title                            | BDD Yet another Publication      |
      | language                         | en                               |
      | field_tax_country                | BDD Germany                      |
      | field_enrd_publ_ehd_rdp          | IE-National                      |
      | field_enrd_publ_ehd_content_type | BDD Glossaries                   |
      | field_enrd_publ_ehd_eval_type    | BDD Ex Ante Evaluation 2014-2020 |
      | field_enrd_publ_ehd_eval_theme   | BDD LEADER-CLLD Evaluation       |

    Then I send the "publication_ehd" to the Solr search index
    And I go to "evaluation/publications"
    # Facet: Content Type
    When I follow "BDD Glossaries"
    Then I should see the heading "BDD Yet another Publication" in the "content" region
    But I should not see the link "BDD Published Evaluation Publication" in the "content" region
    And I follow "Clear filters"
    # Facet: Evaluation Type
    When I follow "BDD Mid-term Evaluation 2007-2013"
    Then I should see the heading "BDD Published Evaluation Publication" in the "content" region
    But I should not see the link "BDD Yet another Publication" in the "content" region
    And I follow "Clear filters"
    # Facet: Evaluation Theme
    When I follow "BDD LEADER-CLLD Evaluation"
    Then I should see the heading "BDD Yet another Publication" in the "content" region
    But I should not see the link "BDD Published Evaluation Publication" in the "content" region
    And I follow "Clear filters"
    # Facet: Country
    When I follow "BDD Ireland"
    Then I should see the heading "BDD Published Evaluation Publication" in the "content" region
    But I should not see the link "BDD Yet another Publication" in the "content" region
    And I follow "Clear filters"
    # The faceted filter is supposed to work even when clicking on the parent term.
    When I follow "European Union"
    Then I should see the heading "BDD Published Evaluation Publication" in the "content" region
    And I should see the heading "BDD Yet another Publication" in the "content" region
    And I follow "Clear filters"
    # Facet: RDP
    When I follow "IE-National"
    Then I should see the heading "BDD Yet another Publication" in the "content" region
    But I should not see the link "BDD Published Evaluation Publication" in the "content" region
    # I should see both content items.
    When I follow "Clear filters"
    Then I should see the link "BDD Published Evaluation Publication" in the "content" region
    And I should see the link "BDD Yet another Publication" in the "content" region
    # Free-text query.
    When I fill in "keys" with "Yet another"
    And I press the "Search" button
    Then I should see the heading "BDD Yet another Publication" in the "content" region
    But I should not see the link "BDD Published Evaluation Publication" in the "content" region

  @anonymous @publication @solr @clean
  Scenario: As Anonymous I can see a subset of Publication's fields both on its published page and on the Solr eLibrary page.
    Given I am an anonymous user
    And "enrd_publications" terms:
      | name                | description                             |
      | BDD EU Rural Review | Description of BDD EU Rural Review      |
    And "project_key_words" terms:
      | name           |
      | BDD Forestry   |
      | BDD Innovation |

    And I am viewing a "publication" content in "published" status:
      | title                            | BDD Custom Publication                       |
      | created                          | 01-01-2017 8:00                              |
      | language                         | en                                           |
      | field_enrd_publication_type      | BDD EU Rural Review                          |
      | field_enrd_publication_desc      | BDD Published Custom Publication Description |
      | field_enrd_publication_date      | 01-04-2020                                   |
      | field_enrd_publication_catal_num | AB-CD-EF-GHI-12-3                            |
      | field_enrd_publication_link_book | http://example.com - http://example.com      |
      | field_enrd_publications_pages    | 15135646                                     |
      | field_enrd_publication_keywords  | BDD Forestry, BDD Innovation                 |

    Then I should see the heading "BDD Custom Publication"
    And I should see "BDD Published Custom Publication Description" in the ".ds-abstract" element
    And I should see "Publication date: April, 2020" in the ".ds-metadata" element
    And I should see "Pages: 15135646" in the ".ds-metadata" element
    And I should see "Keywords: BDD Forestry, BDD Innovation" in the ".ds-metadata" element
    And I should see "Catalogue number: AB-CD-EF-GHI-12-3" in the ".ds-metadata" element
    And I should see "Order a paper copy via the" in the ".ds-metadata" element
    And I should see the link "EU Bookshop" in the "content" region
    And I should see "BDD EU Rural Review" in the ".ds-side" element
    And I should see "Description of BDD EU Rural Review" in the ".ds-side" element

    And I send the "publication" to the Solr search index

    When I am on "publications/search"
    Then I should see the text "BDD Custom Publication"
    And I should see the text "BDD Published Custom Publication Description"
    And I should see the text "Publication date: April, 2020"
    And I should see the text "Keywords: BDD Forestry, BDD Innovation"

  @publication @wip
  Scenario: As Anonymous I want to download the Publication file provided in Spanish.
  # FFR: In order to work, this scenario should be included in the scenario where content has already been created,
  # otherwise the node wouldn't be saved.
    Given I am logged in as a user with the "administrator" role
    And I am at "publications/bdd-custom-publication"
    And I click "New draft"
    And I attach the file "bdd-image.jpg" to "Title page image"
    And I attach the file "bdd-file.pdf" to "media[field_enrd_publication_file_und_0]"
    And I fill in "field_enrd_publication_file[und][0][description]" with "ES"
    And I attach the file "bdd-file.pdf" to "media[field_enrd_publications_rel_docs_und_0]"
    And I select "Published" from "Moderation state"
    And I press the "Save" button

    Given I am an anonymous user
    And I am at "publications/bdd-custom-publication"
    Then I should see the link "ES"

  @editor @publication @workflow @moderate-all
  Scenario: As Editor I can create, edit and moderate a Publication even if created by others.
    Given I am logged in as a user with the "editor" role
    Then I should be able to edit a "publication" content

    Given I am logged in as a user with the "editor" role
    When I am viewing a "publication" content in "needs_review" status:
      | title | BDD editor Publication WF |
    And I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Validated" in the "BDD editor Publication WF" row
    Then I should see the text "Validated" in the "BDD editor Publication WF" row

  @contributor @publication @workflow @moderate-all
  Scenario: As Contributor I can create Publication content but I cannot edit or moderate a Publication created by others.
    Given I am logged in as a user with the "contributor" role
    Then I should not be able to edit a "publication" content

    Given I am logged in as a user with the "contributor" role
    And I am viewing a "publication" content in "draft" status:
      | title | BDD Publication not mine |
    And I am viewing my "publication" with the title "BDD my contributor publication"

    When I go to "admin/workbench"
    And I click "Moderate All"
    Then I should get a 200 HTTP response

    When I click "Change to Needs Review" in the "BDD my contributor publication" row
    Then I should see "Needs Review" in the "BDD my contributor publication" row

    When I click "Change to Needs Review" in the "BDD Publication not mine" row
    Then I should get a 403 HTTP response

  @filters @publication @solr @clean
  Scenario: As Anonymous I want to use the Publications eLibrary's faceted filters to limit results.
    Given I am an anonymous user
    And "enrd_publications" terms:
      | name                           |
      | BDD EU Rural Review            |
      | BDD Rural Connections Magazine |
    And "project_key_words" terms:
      | name           |
      | BDD Forestry   |
      | BDD Innovation |

    And I am viewing a "publication" content in "published" status:
      | title                           | BDD Solr Test Publication |
      | language                        | en                        |
      | field_enrd_publication_type     | BDD EU Rural Review       |
      | field_enrd_publication_keywords | BDD Innovation            |
      | field_enrd_publication_date     | 01-04-2017                |
    And I am viewing a "publication" content in "published" status:
      | title                           | BDD Yet another Solr Test Publication |
      | language                        | en                                    |
      | field_enrd_publication_type     | BDD Rural Connections Magazine        |
      | field_enrd_publication_keywords | BDD Forestry                          |
      | field_enrd_publication_date     | 01-04-2018                            |

    Then I send the "publication" to the Solr search index
    And I go to "publications/search"
    # Facet: Publication type
    When I follow "BDD EU Rural Review"
    Then I should see the heading "BDD Solr Test Publication" in the "content" region
    But I should not see the link "BDD Yet another Solr Test Publication" in the "content" region
    And I follow "Clear filters"
    # Facet: Keywords
    When I follow "BDD Forestry"
    Then I should see the heading "BDD Yet another Solr Test Publication" in the "content" region
    But I should not see the link "BDD Solr Test Publication" in the "content" region
    # Facet: Publication date
    When I follow "2018"
    Then I should see the heading "BDD Yet another Solr Test Publication" in the "content" region
    But I should not see the link "BDD Solr Test Publication" in the "content" region
    # I should see both content items.
    When I follow "Clear filters"
    Then I should see the link "BDD Solr Test Publication" in the "content" region
    And I should see the link "BDD Yet another Solr Test Publication" in the "content" region
    # Free-text query.
    When I fill in "keys" with "Yet another"
    And I press the "Search" button
    Then I should see the heading "BDD Yet another Solr Test Publication" in the "content" region
    But I should not see the link "BDD Solr Test Publication" in the "content" region

  @anonymous @evaluation @pinned @solr @clean
  Scenario: As Anonymous I can see pinned Evaluation Publications on top of standard Evaluation Publications after
   landing on the Evaluation eLibrary.
    Given I am an anonymous user
    And "enrd_evaluation_content_type" terms:
      | name           |
      | BDD Reports    |
      | BDD Glossaries |

    When I am viewing a "publication_ehd" content in "published" status:
      | title                             | BDD Custom Pinned Evaluation Publication |
      | language                          | en                                |
      | field_enrd_publ_ehd_content_type  | BDD Reports                       |
      | sticky                            | 1                                 |
    And I am viewing a "publication_ehd" content in "published" status:
      | title                             | BDD Unpinned Evaluation Publication |
      | language                          | en                                  |
      | field_enrd_publ_ehd_content_type  | BDD Reports                         |
      | sticky                            | 0                                   |
    And I am viewing a "publication_ehd" content in "published" status:
      | title                             | BDD Custom Evaluation Publication   |
      | language                          | en                                  |
      | sticky                            | 0                                   |

    And I send the "publication_ehd" to the Solr search index
    When I am on "evaluation/publications"

    Then I should see "BDD Custom Pinned Evaluation Publication" in the ".node-sticky" element
    And I should not see "BDD Unpinned Evaluation Publication" in the ".node-sticky" element

    # The pinned EHD Publication should be displayed also if relevant to the filter/free-text query.
    When I follow "BDD Reports"
    Then I should see "BDD Custom Pinned Evaluation Publication" in the ".node-sticky" element
    And I should see the heading "BDD Unpinned Evaluation Publication"
    But I should not see "BDD Unpinned Evaluation Publication" in the ".node-sticky" element

    When I fill in "keys" with "Custom"
    And I press the "Search" button
    Then I should see "BDD Custom Pinned Evaluation Publication" in the ".node-sticky" element
    And I should see the heading "BDD Custom Evaluation Publication"
    But I should not see "BDD Custom Evaluation Publication" in the ".node-sticky" element

  @anonymous @publication @pinned @solr @clean
  Scenario: As Anonymous I can see pinned CP Publications on top of standard Publications after
   landing on the Publications eLibrary.
    Given I am an anonymous user
    And "enrd_publications" terms:
      | name                           |
      | BDD EU Rural Review            |
      | BDD Rural Connections Magazine |
    And "project_key_words" terms:
      | name           |
      | BDD Forestry   |
      | BDD Innovation |

    When I am viewing a "publication" content in "published" status:
      | title                           | BDD Custom Pinned Publication |
      | language                        | en                            |
      | field_enrd_publication_type     | BDD EU Rural Review           |
      | field_enrd_publication_keywords | BDD Forestry                  |
      | sticky                          | 1                             |
    And I am viewing a "publication" content in "published" status:
      | title                           | BDD Unpinned Publication       |
      | language                        | en                             |
      | field_enrd_publication_type     | BDD EU Rural Review            |
      | field_enrd_publication_keywords | BDD Forestry                   |
      | sticky                          | 0                              |
    And I am viewing a "publication" content in "published" status:
      | title                           | BDD Custom Magazine            |
      | language                        | en                             |
      | field_enrd_publication_type     | BDD Rural Connections Magazine |
      | field_enrd_publication_keywords | BDD Innovation                 |
      | sticky                          | 0                              |

    Then I send the "publication" to the Solr search index
    And I go to "publications/search"

    Then I should see "BDD Custom Pinned Publication" in the ".node-sticky" element
    And I should not see "BDD Unpinned Publication" in the ".node-sticky" element

    # The pinned Publication should be displayed also if relevant to the filter/free-text query.
    When I follow "BDD EU Rural Review"
    Then I should see "BDD Custom Pinned Publication" in the ".node-sticky" element
    And I should see the heading "BDD Unpinned Publication"
    But I should not see "BDD Unpinned Publication" in the ".node-sticky" element

    When I fill in "keys" with "Custom"
    And I press the "Search" button
    Then I should see "BDD Custom Pinned Publication" in the ".node-sticky" element
    And I should see the heading "BDD Custom Magazine"
    But I should not see "BDD Custom Magazine" in the ".node-sticky" element
