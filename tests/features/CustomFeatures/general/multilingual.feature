@api
Feature: ENRD Multilingual Environment
  In order to navigate a multilingual portal
  As anonymous user
  - I can see the translated version (if exist) of content or the english version as fallback;
  - landed in the home page I can choose the language to navigate into the site;

  In order to manage translations
  As editor
  - I can translate a content;

  @anonymous @lang-selection
  Scenario: View translation that exist for the content or the english fallback
    Given I am an anonymous user
    And I am viewing a multilingual "page" content:
      | language | title            |
      | en       | Title in English |
      | it       | Title in Italian |
    When I follow "Italiano"
    Then I should see the heading "Title in Italian"
    And the url should match "_it"
    When I follow "English"
    Then I should see the heading "Title in English"
    And the url should match "_en"
    When I follow "Français"
    Then I should see the heading "Title in English"
    But the url should match "_fr"
    # Check for translated messages on language fallback.
    And I am viewing a multilingual "page" content:
      | language | title                     |
      | en       | Page with no translations |
    When I follow "Français"
    Then I should see the heading "Page with no translations"
    And I should see "Français non disponible" in the ".lang-select-page__not-available" element
    And I should see "English" in the ".lang-select-page__served" element
    But the url should match "_fr"
    When I follow "Deutsch"
    Then I should see the heading "Page with no translations"
    And I should see "Deutsch nicht verfügbar" in the ".lang-select-page__not-available" element
    And I should see "English" in the ".lang-select-page__served" element
    But the url should match "_de"
    When I follow "Italiano"
    Then I should see the heading "Page with no translations"
    And I should see "Italiano non disponibile" in the ".lang-select-page__not-available" element
    And I should see "English" in the ".lang-select-page__served" element
    But the url should match "_it"
    When I follow "Español"
    Then I should see the heading "Page with no translations"
    And I should see "Español no disponible" in the ".lang-select-page__not-available" element
    And I should see "English" in the ".lang-select-page__served" element
    But the url should match "_es"
    When I follow "Polski"
    Then I should see the heading "Page with no translations"
    And I should see "Polski niedostępny" in the ".lang-select-page__not-available" element
    And I should see "English" in the ".lang-select-page__served" element
    But the url should match "_pl"

  @anonymous @lang-selection
  Scenario: Using the language selector and prefix fallback uri
    Given I am an anonymous user
    And I am on the homepage
    When I follow "Italiano"
    Then I see the text "La Rete europea per lo sviluppo rurale"
    And the url should match "_it"

  @editor
  Scenario: Editor can translate an entity content
    Given I am logged in as a user with the "editor" role
    When I am viewing a "page" content in "validated" status:
      | title | BDD translatable page |
    Then I should see the link "Translate"
