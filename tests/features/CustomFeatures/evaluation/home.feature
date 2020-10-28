@api @ehd-home @evaluation @anonymous
Feature: ENRD Evaluation home.
  This feature is aimed at creating a dynamic Evaluation Helpdesk's Landing page.
  An Anonymous user can find a sliding block containing the latest Evaluation publications, a sliding block with
  the Basic pages and Events tagged by the "Evaluation Helpdesk" taxonomy term, a "Latest tweets" block and
  a static "Events" block containing the latest Evaluation events and, only if inserted by an editor user, the
  "Evaluation" basic page fields.

  Background: Create the Main EHD Landing page and the "Evaluation Helpdesk" technical taxonomy term.
    Given 'enrd_origin' terms:
      | name                |
      | Evaluation Helpdesk |
    And I am viewing a "page" content in "published" status:
      | title               | Evaluation                     |
      | body                | BDD who we are                 |
      | field_page_info_box | BDD info box                   |
      | field_page_sidebar  | BDD main sidebar right content |

  @clean
  Scenario: As Anonymous I can see the basic fields of the Main EHD Landing page.
    Given I am an anonymous user
    When I go to "evaluation"
    Then I should see the heading "Evaluation"
    And I should see the link "More tweets"
    And I should see "BDD who we are" in the "content" region
    And I should see "BDD info box" in the "content" region
    And I should see "BDD main sidebar right content" in the "right sidebar" region

  @clean
  Scenario: As Anonymous I cannot see the dynamic blocks if there is no related published content.
    Given I am an anonymous user
    When I go to "evaluation"
    Then I should not see "Latest publications" in the "content" region
    Then I should not see "Evaluation updates" in the "content" region
    Then I should not see "Events" in the "right sidebar" region

  Scenario: As Anonymous I can see a "Latest publications" dynamic block and an EHD published Publication.
  I can also click on the "All publications" button so that I can see the list of EHD publications.
    Given I am an anonymous user
    And I am viewing a "publication_ehd" content in "published" status:
      | title                        | BDD Evaluation Landing Publ          |
      | field_enrd_publ_ehd_abstract | BDD Evaluation Landing Publ Abstract |
      | sticky                       | 1                                    |
      | created                      | today 8:00                           |

    When I go to "evaluation"
    Then I should see "Latest publications" in the "content" region
    And I should see the heading "BDD Evaluation Landing Publ"
    And I should see the text "BDD Evaluation Landing Publ Abstract"

    When I click "All publications"
    Then I should see the text "Search Evaluation Publications"

  @news @taxonomies
  Scenario: As Anonymous I can see an "Evaluation updates" dynamic block and I can see either a Basic page or a News
  tagged by the technical taxonomy term "Evaluation Helpdesk".
    Given I am an anonymous user
    When I am viewing a "page" content in "published" status:
      | title            | BDD Evaluation Landing sample page                 |
      | created          | today 8:00                                         |
      | body             | BDD The body of BDD Evaluation Landing sample page |
      | field_tax_origin | Evaluation Helpdesk                                |

    When I go to "evaluation"
    Then I should see "Evaluation updates" in the "content" region
    And I should see the heading "BDD Evaluation Landing sample page"
    And I should see the text "BDD The body of BDD Evaluation Landing sample page"

    Then I am viewing a "news" content in "published" status:
      | title            | BDD Evaluation Landing sample News                 |
      | created          | today 8:00                                         |
      | body             | BDD The body of BDD Evaluation Landing sample News |
      | field_tax_origin | Evaluation Helpdesk                                |

    When I go to "evaluation"
    Then I should see "Evaluation updates" in the "content" region
    And I should see the heading "BDD Evaluation Landing sample News"
    And I should see the text "BDD The body of BDD Evaluation Landing sample News"

  @events @taxonomies @clean
  Scenario: As Anonymous I can see an "Events" dynamic block and I can see two Events tagged by the
  technical taxonomy term "Evaluation Helpdesk".
    Given I am an anonymous user
    And I am viewing an "event" content in "published" status:
      | title                         | BDD Evaluation Landing sample Event |
      | field_event_date              | 01-03-2018 - 01-01-2019             |
      | field_event_location:country  | AT                                  |
      | field_event_location:locality | Vienna                              |
      | field_tax_origin              | Evaluation Helpdesk                 |
      | field_enrd_event_online       | 1                                   |
    And I am viewing an "event" content in "published" status:
      | title                         | BDD Evaluation Landing custom Event |
      | field_event_date              | 01-01-2018 - 01-01-2018             |
      | field_event_location:country  | BE                                  |
      | field_event_location:locality | Brussels                            |
      | field_tax_origin              | Evaluation Helpdesk                 |

    When I go to "evaluation"
    Then I should see "Events" in the "right sidebar" region
    And I should see the heading "BDD Evaluation Landing sample Event" in the "right sidebar" region
    And I should see the text "Dates: 01/03/2018 to 01/01/2019" in the "right sidebar" region
    And I should see the text "Location: Vienna, Austria" in the "right sidebar" region
    And I should see the heading "BDD Evaluation Landing custom Event" in the "right sidebar" region
    And I should see the text "Dates: 01/01/2018" in the "right sidebar" region
    And I should see the text "Location: Brussels, Belgium" in the "right sidebar" region

    # Check "online" Event visibility.
    And I should see the ".online" element in the "right sidebar" region
