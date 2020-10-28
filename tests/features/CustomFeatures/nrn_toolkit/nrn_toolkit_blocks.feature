@api @nrn-toolkit
Feature: ENRD NRN Toolkit.
  This Feature aims check whether the NRN menus are set up in the right way.

  @nrn-static
  Scenario: As anonymous user I should see a NRN menu to navigate NRN static pages.
    Given I am an anonymous user
    And I am on the homepage
    Then I should see "NRN Toolkit" in the "left sidebar" region
    When I follow "NRN Toolkit"
    # TODO: check for content of destination page when the placeholder will be removed.
    And I should see "NRN Profiles" in the "content" region
    # TODO: check for content of destination page when the placeholder will be removed.
    And I should see "NRN meetings & workshops" in the "content" region
    # TODO: check for content of destination page when the placeholder will be removed.
    And I should see "Multimedia" in the "content" region

  @nrn-intro-block
  Scenario: As Webmaster user I should be able to set the NRN Intro text, while as Anonymous to see it in the Landing page.

    Given I am logged in as a user with the "webmaster" role
    And I am at "admin/content/blocks"
    And I click "edit" in the "NRN Toolkit intro" row
    And I fill in "Block Body" with "BDD NRN Toolkit Intro text."
    And I press "Save"

    Given I am an anonymous user
    And I go to "networking/nrn-toolkit"
    Then I should see the text "BDD NRN Toolkit Intro text." in the "content" region

  @nrn-static
  Scenario: As webmaster I should be able to add or delete a NRN static pages menu item.
    Given I am logged in as a user with the "webmaster" role
    And I am at "admin/structure/menu/manage/menu-enrd-nrn-static-pages"
    And I follow "Add link"
    And I fill in "Menu link title" with "BDD menu item"
    And I fill in "Path" with "<front>"
    And I press "Save"
    And I am at "networking/nrn-toolkit"
    Then I should see "BDD menu item" in the "content" region
    When I am at "admin/structure/menu/manage/menu-enrd-nrn-static-pages"
    Then I should see "BDD menu item"
    When I click "delete" in the "BDD menu item" row
    And I press the "Confirm" button
    Then I should see the following success messages:
      | success messages                              |
      | The menu link BDD menu item has been deleted. |
    When I am at "networking/nrn-toolkit"
    Then I should not see the link "BDD menu item"