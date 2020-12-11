@api @contentactivities
Feature: ENRD Content Activities

  This feature is aimed at allowing a site webmaster to supervise any site contents' activities, all listed in tabular form.
  It also allows to search for content activities by applying several filter criteria and to download a CSV report listing the search results in tabular form.

  @workflow @no-og
  Scenario: Test if a general Basic page creation, modification, moderation and deletion is reported on the Content Activities report page.
    Given users:
      | name               | mail                           | pass | roles     |
      | bdd-user-webmaster | bdd-user-webmaster@example.com | test | webmaster |
      | bdd-john-doe       | bdd-john-doe@example.com       | test | webmaster |
    # New content creation + New Draft creation.
    Given I am logged in as "bdd-user-webmaster"
    And I am at "node/add/page"
    And I fill in "title_field[en][0][value]" with "BDD Content Activities test page"
    And I press "Save"
    When I go to "admin/reports/content-activities"
    Then I should see the text 'A new Basic page: BDD Content Activities test page has been created by bdd-user-webmaster'
    And I should see the text 'A Draft of the Basic page: BDD Content Activities test page has been created by bdd-user-webmaster'
    # Draft -> Needs Review Workbench Transition.
    Given I am logged in as "bdd-john-doe"
    When I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Needs Review" in the "BDD Content Activities test page" row
    Then I should see the text "Change to Draft" in the "BDD Content Activities test page" row

    When I go to "admin/reports/content-activities"
    Then I should see the text 'The Basic page: BDD Content Activities test page has changed moderation state from Draft to Needs Review'
    # Content update.
    And I should see the text 'The Basic page: BDD Content Activities test page has been updated by bdd-john-doe'
    But I should not see the text 'The Basic page: BDD Content Activities test page has been updated by bdd-user-webmaster'
    # Needs Review -> Validated Workbench Transition.
    When I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Validated" in the "BDD Content Activities test page" row
    Then I should see the text "Change to Needs Review" in the "BDD Content Activities test page" row

    When I go to "admin/reports/content-activities"
    Then I should see the text 'The Basic page: BDD Content Activities test page has changed moderation state from Needs Review to Validated'
    # Validated -> Published Workbench Transition.
    When I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Published" in the "BDD Content Activities test page" row
    Then I should see the text "Change to Validated" in the "BDD Content Activities test page" row

    When I go to "admin/reports/content-activities"
    Then I should see the text 'The Basic page: BDD Content Activities test page has changed moderation state from Validated to Published'
    # Published -> Archived Workbench Transition.
    When I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Archived" in the "BDD Content Activities test page" row
    Then I should see the text "Change to Published" in the "BDD Content Activities test page" row

    When I go to "admin/reports/content-activities"
    Then I should see the text 'The Basic page: BDD Content Activities test page has changed moderation state from Published to Archived'
    # Content deletion.
    When I am on "bdd-content-activities-test-page"
    And I follow "Edit draft"
    And I press "Delete"
    And I press "Delete"
    When I go to "admin/reports/content-activities"
    Then I should see the text 'The Basic page: BDD Content Activities test page has been deleted by bdd-john-doe'
    But I should not see the text 'The Basic page: BDD Content Activities test page has been deleted by bdd-user-webmaster'

  # Messages related to OG Workbench moderation are obsolete and no more applicable if OG content is LAG or Coop. offer.
  @workflow @og
  Scenario: Test if OG content creation, modification, moderation and deletion is reported on the Activities report page.
    Given users:
      | name              | mail                          | pass | roles                         |
      | bdd-comm-adm      | bdd-comm-adm@example.com      | test | authenticated user, webmaster |
      | bdd-comm-jane-doe | bdd-comm-jane-doe@example.com | test | authenticated user, webmaster |
    Given I am viewing a "community" content in "published" status:
      | title | BDD Content Activities Comm |
    When I am logged in as "bdd-comm-adm"
    And I have the "administrator member" role in the "BDD Content Activities Comm" group
    And I am logged in as "bdd-comm-jane-doe"
    And I have the "administrator member" role in the "BDD Content Activities Comm" group
    # New content creation + New Draft creation.
    Given I am logged in as "bdd-comm-adm"
    And I am at "community/bdd-content-activities-comm"
    And I follow "News" in the "right sidebar" region
    And I fill in "title_field[en][0][value]" with "BDD Content Activities test comm news"
    And I press "Save"
    When I go to "admin/reports/content-activities"
    Then I should see the text "A new News BDD Content Activities test comm news has been created by bdd-comm-adm in group BDD Content Activities Comm"
    And I should see the text "A Draft of the News: BDD Content Activities test comm news has been created by bdd-comm-adm"
    # Draft -> Needs Review Workbench Transition.
    Given I am logged in as "bdd-comm-jane-doe"
    And I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Needs Review" in the "BDD Content Activities test comm news" row
    Then I should see the text "Change to Draft" in the "BDD Content Activities test comm news" row

    When I go to "admin/reports/content-activities"
    Then I should see the text 'The News: BDD Content Activities test comm news has changed moderation state from Draft to Needs Review'
    # Content update.
    And I should see the text "The News: BDD Content Activities test comm news has been updated by bdd-comm-jane-doe in group BDD Content Activities Comm"
    But I should not see the text "The News: BDD Content Activities test comm news has been updated by bdd-comm-adm in group BDD Content Activities Comm"
    # Needs Review -> Validated Workbench Transition
    When I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Validated" in the "BDD Content Activities test comm news" row
    Then I should see the text "Change to Needs Review" in the "BDD Content Activities test comm news" row

    When I go to "admin/reports/content-activities"
    Then I should see the text 'The News: BDD Content Activities test comm news has changed moderation state from Needs Review to Validated'
    # Validated -> Published Workbench Transition.
    When I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Published" in the "BDD Content Activities test comm news" row
    Then I should see the text "Change to Validated" in the "BDD Content Activities test comm news" row

    When I go to "admin/reports/content-activities"
    Then I should see the text 'The News: BDD Content Activities test comm news has changed moderation state from Validated to Published'
    # Published -> Archived Workbench Transition.
    When I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Archived" in the "BDD Content Activities test comm news" row
    Then I should see the text "Change to Published" in the "BDD Content Activities test comm news" row

    When I go to "admin/reports/content-activities"
    Then I should see the text 'The News: BDD Content Activities test comm news has changed moderation state from Published to Archived'
    # Content deletion.
    When I am on "news-events/news/bdd-content-activities-test-comm-news"
    And I follow "Edit draft"
    And I press "Delete"
    And I press "Delete"
    When I go to "admin/reports/content-activities"
    Then I should see the text 'The News: BDD Content Activities test comm news has been deleted by bdd-comm-jane-doe'
    But I should not see the text 'The News: BDD Content Activities test comm news has been deleted by bdd-comm-adm'
