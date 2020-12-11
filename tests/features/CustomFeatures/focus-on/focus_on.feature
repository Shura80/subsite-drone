@api @focus-on
Feature: ENRD Focus on.
  This Feature aims to create a "Focus on" content type that can reference nodes
  of other content types to show them as higlighted content on the Home page of
  the site.

  Background: Create a bunch of nodes to test roles permissions.
    # Create a node of type project to reference in "Focus on".
    Given I am viewing a "project" content in "published" status:
      | title | BDD Published Project |

  @webmaster @editor @anonymous @javascript @clean
  Scenario Outline: As anonymous user, I can see the homepage block with the published focuses on.
  Both Webmaster and Editor users are allowed to insert a Focus on in the queue.
    Given I am logged in as a user with the "<role>" role
    And I am viewing a "focus_on" content in "published" status:
      | title                           | BDD Published Focus on |
      | field_enrd_focus_on_description | BDD Desc Focus on      |
    When I am at "admin/structure/entityqueue"
    And I click "Edit items" in the "Focus on - Home page slider" row
    And I fill in the autocomplete "edit-eq-node-und-add-entity" with "BDD Published Focus on" and click "BDD Published Focus on"
    And I press the "Add item" button
    And I press "Save"

    Given I am an anonymous user
    When I am on the homepage
    Then I should see "BDD Published Focus on"
    Then I should see "BDD Desc Focus on"

    Examples:
      | role      |
      | webmaster |
      | editor    |

  @required
  Scenario: Check for required fields when creating a "Focus on".
    Given I am logged in as a user with the "webmaster" role
    When I am at "node/add/focus-on"
    And I press the "Save" button
    Then I should see the following error message:
      | error messages                 |
      | Title field is required.       |
      | Description field is required. |
      | Highlight field is required.   |
      | Image field is required.       |

  @published @wip
  # Fix with media browser test.
  Scenario: Create a "Focus on" node and check how it displays info in the frontend.
    Given I am an anonymous user
    And I am on "focus-on/bdd-focus-pub"
    Then I should see the heading "BDD Focus PUB"
    And I should see "Description: BDD Lorem ipsum"
    And I should see "Highlight: BDD Published Project"

    Given I am logged in as a user with the "webmaster" role
    And I am on "focus-on/bdd-focus-pub"
    And I click "New draft"
    And I attach the file "bdd-image.jpg" to "field-name-field-enrd-focus-on-image"
    And I select "published" from "edit-state"
    And I press "Save"
    Then I should see the heading "BDD Focus PUB"
    And I should see the "field-name-field-enrd-focus-on-image" element in the "content" region
    And I should see "Description: BDD Lorem ipsum"
    And I should see "Highlight: BDD Published Project"

  @permissions
  Scenario: Check for creating a new "Focus on" permissions.
    Given I am logged in as a user with the "webmaster" role
    When I am on "node/add"
    Then I should see the link "Focus on"

    Given I am logged in as a user with the "editor" role
    When I am on "node/add"
    Then I should see the link "Focus on"

    Given I am logged in as a user with the "contributor" role
    When I am on "node/add"
    Then I should see the link "Focus on"

    Given I am logged in as a user with the "publisher" role
    When I am on "node/add"
    Then I should not see the link "Focus on"

  # WEBMASTER
  @workflow @webmaster
  Scenario: Check webmasters moderation tasks for the Focus on content type.
    Given I am logged in as a user with the "webmaster" role
    And I am viewing a "focus_on" content in "draft" status:
      | title | BDD Focus On draft |

    # From Draft state.
    When I select "needs_review" from "edit-state"
    And I press "Apply"
    Then I should see "Revision state: Needs Review"

    # From Needs review state.
    And I select "validated" from "edit-state"
    And I press "Apply"
    Then I should see "Revision state: Validated"

    # From Validated state.
    When I select "published" from "edit-state"
    And I press "Apply"
    Then I should see "Revision state: Published"

    # From Published state.
    When I click "Unpublish"
    And I select "archived" from "edit-state"
    And I press "Unpublish"
    Then I should see "The current state is Archived."

  # EDITOR
  @workflow @editor
  Scenario: Check editors moderation tasks.
    Given I am logged in as a user with the "editor" role
    And I am viewing a "focus_on" content in "draft" status:
      | title | BDD Another Focus On in draft |

    # From Draft state.
    When I select "needs_review" from "edit-state"
    And I press "Apply"
    Then I should see "Revision state: Needs Review"

    # From Needs review state.
    And I select "validated" from "edit-state"
    And I press "Apply"
    Then I should see "Revision state: Validated"

    # From Published state.
    When I am viewing a "focus_on" content in "published" status:
      | title                           | BDD Another published Focus on |
      | field_enrd_focus_on_description | BDD Lorem ipsum                |
      | field_enrd_focus_on_highlight   | BDD Published Project          |
    And I click "Unpublish"
    And I select "archived" from "edit-state"
    And I press "Unpublish"
    Then I should see "The current state is Archived."

  # CONTRIBUTOR
  @workflow @contributor
  Scenario: Check contributors moderation tasks:
    Given I am logged in as a user with the "contributor" role
    And I am viewing a "focus_on" content in "draft" status:
      | title                           | BDD Focus contributor |
      | field_enrd_focus_on_description | BDD Lorem ipsum       |
      | field_enrd_focus_on_highlight   | BDD Published Project |
      | author                          | myself                |

    # From Draft to Needs review.
    When I select "needs_review" from "edit-state"
    And I press "Apply"
    Then I should see "Revision state: Needs Review"

    # From Needs Review to Draft.
    When I select "draft" from "edit-state"
    And I press "Apply"
    Then I should see "Revision state: Draft"

  # PUBLISHER
  @workflow @publisher
  Scenario: Check publishers moderation tasks:
    Given I am logged in as a user with the "editor, publisher" roles

    # From Needs review state.
    And I am viewing a "focus_on" content in "needs_review" status:
      | title                           | BDD Focus NRE         |
      | field_enrd_focus_on_description | BDD Lorem ipsum       |
      | field_enrd_focus_on_highlight   | BDD Published Project |
    When I select "published" from "edit-state"
    And I press "Apply"
    Then I should see "Revision state: Published"

    # From Validated state.
    When I am viewing a "focus_on" content in "validated" status:
      | title                           | BDD Focus VAL         |
      | field_enrd_focus_on_description | BDD Lorem ipsum       |
      | field_enrd_focus_on_highlight   | BDD Published Project |
    And I select "published" from "edit-state"
    And I press "Apply"
    Then I should see "Revision state: Published"

    # From Published state.
    And I click "Unpublish"
    And I select "archived" from "edit-state"
    And I press "Unpublish"
    Then I should see "The current state is Archived."
