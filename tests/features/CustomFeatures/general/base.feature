@api @mastermind
Feature: ENRD Basic functionalities

  @anonymous
  Scenario: Home page and Basic page navigation for anonymous user
    Given I am an anonymous user
    And I am viewing a "page" content in "published" status:
      | title               | BDD Published page     |
      | body                | BDD The body of page   |
      | field_page_info_box | BDD Content of infobox |
      | field_page_sidebar  | BDD Content of sidebar |
    And I should see the heading "BDD Published page" in the "title"
    And I should see "The body of page"
    And I should see "Content of infobox"
    And I should see "Content of sidebar" in the "right sidebar"
    And I should not see the heading "Add new comment"

    When I am on the homepage
    Then I should see the link "Site Map" in the "top header" region
    And I should see the heading "Join Us" in the "left sidebar"
    And I should see the heading "ENRD Tweets" in the "right content" region
    And I should see "Last updated:" in the "footer"
    And I should see the link "Top" in the "footer"

  @anonymous
  Scenario: Public registrations are allowed only by ECAS.
    Given I am an anonymous user
    When I go to "user/register"
    Then I should get an access denied error

  @authenticated
  Scenario: Authenticated user cannot see My workbench
    Given I am logged in as a user with the "authenticated user" role
    When I am on the homepage
    Then I should not see the link "My workbench" in the "tools"

  @editor
  Scenario: Editor can access to Admin menu, My workbench and create some basic contents.
    Given I am logged in as a user with the "editor" role
    Then I should see the link "Help"

    When I go to "admin/workbench"
    Then I should get a 200 HTTP response

    When I click "Create content"
    Then I should see the link "Basic page"
    And I should see the link "Focus group"
    And I should see the link "Organization"
    And I should see the link "Gallery"
    And I should see the link "Document"
    But I should not see the link "Article"

  @editor @workflow @moderate-all
  Scenario Outline: Editor can moderate some content.
    Given I am logged in as a user with the "editor" role

    When I am viewing a "<content type>" content in "needs_review" status:
      | title | BDD editor workflow 1st <content type> |
    And I am viewing a "<content type>" content in "published" status:
      | title | BDD editor workflow 2nd <content type> |
    Then I should see the link "Moderate"

    When I go to "admin/workbench"
    And I click "Moderate All"
    Then I should get a 200 HTTP response

    When I click "Change to Draft" in the "BDD editor workflow 1st <content type>" row
    Then I should see the "Change to Needs Review" in the "BDD editor workflow 1st <content type>" row
    And I should see the "Change to Validated" in the "BDD editor workflow 1st <content type>" row
    And I should see "Validated" in the "BDD editor workflow 1st <content type>" row

    When I click "Change to Archived" in the "BDD editor workflow 2nd <content type>" row
    Then I should see "Archived" in the "BDD editor workflow 2nd <content type>" row

    Examples:
      | content type |
      | page         |
      | focus_group  |
      | organization |

  @contributor
  Scenario: Contributor can access to My workbench and create some basic contents.
    Given I am logged in as a user with the "contributor" role
    When I go to "admin/workbench"
    And I click "Create content"
    Then I should see the link "Basic page"
    And I should see the link "Focus group"
    And I should see the link "Organization"
    And I should see the link "Gallery"
    And I should see the link "Document"
    But I should not see the link "Article"

  @contributor @workflow @moderate-all
  Scenario Outline: As contributor I can moderate only mine content.

    Given I am logged in as a user with the "contributor" role
    And I am viewing a "<content type>" content in "draft" status:
      | title | BDD not mine <content type> |
    And I am viewing my "<content type>" with the title "BDD my contributor <content type>"

    When I go to "admin/workbench"
    And I click "Moderate All"
    Then I should get a 200 HTTP response

    When I click "Change to Needs Review" in the "BDD my contributor <content type>" row
    Then I should see "Needs Review" in the "BDD my contributor <content type>" row

    When I click "Change to Needs Review" in the "BDD not mine <content type>" row
    Then I should get a 403 HTTP response

    Examples:
      | content type |
      | page         |
      | focus_group  |
      | organization |

  @publisher @workflow @moderate-all
  Scenario Outline: As publisher I can publish contents.

    Given I am logged in as a user with the "editor, publisher" roles
    And I am viewing a "<content type>" content in "validated" status:
      | title | BDD validated <content type> |

    When I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Published" in the "BDD validated <content type>" row
    Then I should see "Published" in the "BDD validated <content type>" row

    Examples:
      | content type |
      | page         |
      | focus_group  |
      | organization |

  @javascript @webmaster @filters
  Scenario: Insert links in content textareas through CKEditor "Insert internal links" functionality
    Given I am logged in as a user with the "webmaster" role
    And "page" content:
      | title             | status |
      | BDD Linkable page | 1      |
    When I am creating a "page" content
    And I click the "Insert internal content" button in the "Body" WYSIWYG editor
    And I wait for AJAX to finish
    Then I should see the "CKEditor" modal dialog from the "Body" WYSIWYG editor with "Insert internal content" title
    And I wait for AJAX to finish
    Then I should see "BDD Linkable page" in the "Title" row

  @ckeditor @clean
  Scenario: CKEditor links will be handled by Nexteuropa Tokens filter
    Given I am an anonymous user
    And I am viewing a "page" content in "published" status:
      | title      | BDD CKEditor filter fallback            |
      | body:value | <a href="/node/999999999">Fake link</a> |
      | :format    | full_html                               |
    When I am logged in as a "webmaster"
    And I go to "admin/reports/dblog"
    And select "Nexteuropa Tokens" from "Type"
    And I press the "Filter" button
    Then I should see the text "The entity BDD CKEditor filter fallback" in the "Nexteuropa Tokens" row

  @anonymous @filters
  Scenario Outline: All emails within CKEditor text fields are filtered to be hidden from spam-bots.
    Given I am an anonymous user
    And I am viewing a "page" content in "published" status:
      | title      | BDD Invisimail Email <format> test        |
      | body:value | John Doe's email is: john_doe@example.com |
      | :format    | <format>                                  |

    Then I should see the link "john_doe@example.com" in the "content" region
    And I should see the "a" element with the "href" attribute set to "mailto:john_doe@example.com" in the "content" region

    Examples:
      | format         |
      | full_html      |
      | filtered_html  |
      | enrd_safe_html |

  @webmaster @clean
  Scenario: As webmaster I want to be able to display a sitewide disclaimer in the Footer Top region.
    Given I am logged in as a user with the "webmaster" role
    And I am at "block/footertopdisclaimer/edit"
    And I fill in "Block Body" with "<div class=\"alert alert-warning\" role=\"alert\" style=\"margin:0; padding:0.6em 1em; font-size:10px;word-spacing: -0.5px;\">This is a Footer Top disclaimer.</div>"
    And I press "Save"
    Given I am an anonymous user
    Then I should see "This is a Footer Top disclaimer." in the "footer top" region

  @footer @last-update-info
  Scenario: As user I should receive different messages in the footer content block
  depending on what I am watching (node, user, file, view, solr page, junction page, etc...).
    Given I am logged in as a user with the "webmaster, User management" roles
    # Create user to check later visibility of 'Last accessed' user info.
    And users:
      | name            |
      | bdd-user-footer |
    # Create a test keyword to test the default message later.
    And 'tags' terms:
      | name        |
      | BDD Keyword |
    # Create a file to check later visibility of 'Last uploaded' file info.
    And an image "bdd-image.jpg" with the caption "BDD Image footer info"
    # Create a basic page to check later visibility of 'Last updated' node info.
    And I am viewing a "page" content in "published" status:
      | title | BDD Test footer page |
    # Add the custom page node to the skipped path to check if default message is displayed.
    Then I should see "Last updated:" in the footer
    # Files
    When I am at "admin/content/file"
    And I click "bdd-image.jpg" in the "bdd-image.jpg" row
    Then I should see "Last uploaded:" in the footer
    And I should not see "Last updated:" in the footer
    # User profiles.
    When I am at "admin/nexteuropa-user-management"
    And I fill in "Ecas username" with "bdd-user-footer"
    And I press "Apply"
    And I click "bdd-user-footer"
    Then I should see "Last accessed: never" in the footer
    And I should not see "Last updated:" in the footer
    # Taxonomy terms.
    When I am at "tags/bdd-keyword"
    Then I should see "Last updated:" in the footer

  @webmasters @menu-token
  Scenario: As a webmaster I can set a menu token to render 2nd level navigation of a custom menu
  and use icons and classes to apply custom styles.
    Given I am logged in as a user with the "webmaster" role
      # Create the parent page with token and menu item.
    And "page" content:
      | title                | status |
      | BDD menu parent page | 1      |
    And I am at "bdd-menu-parent-page"
    And I click "New draft"
    And I fill in "Body" with "[menu:menu-enrd-portals]"
    And I check the box "Provide a menu link"
    And I fill in "Menu link title" with "BDD Parent"
    And I select "<Portals>" from "Parent item"
    And I select "right-open" from "Icon"
    And I fill in "Classes" with "bdd-menu-parent"
    And I select "Published" from "Moderation state"
    And I press "Save"
      # Create the child page with token and menu item.
    And "page" content:
      | title               | status |
      | BDD menu child page | 1      |
    And I am at "bdd-menu-child-page"
    And I click "New draft"
    And I fill in "Body" with "[menu:menu-enrd-portals]"
    And I check the box "Provide a menu link"
    And I fill in "Menu link title" with "BDD Child"
    And I select "BDD Parent" from "Parent item"
    And I select "ok" from "Icon"
    And I select "Published" from "Moderation state"
    And I press "Save"
      # Parent item page.
    When I am at "bdd-menu-parent-page"
    Then I should see the heading "BDD menu parent page"
      # Check that parent menu item, data-image attribute and icon classes have been set in left sidebar menu block.
    And I should see "BDD Parent" in the "left sidebar" region
    And I should see the ".block-icons-menu a" element with the "data-image" attribute set to "right-open" in the "left sidebar" region
    And I should see the ".block-icons-menu span.icon.icon-right-open" element in the "left sidebar" region
      # Check that parent item class has been applied on menu container.
    And I should see the ".enrd-token-menu.bdd-menu-parent" element in the "content" region
      # Check that child menu item, data-image attribute and icon classes have been set in the content menu navigation block.
    And I should see the "div.bdd-menu-parent a" element with the "data-image" attribute set to "ok" in the "content" region
    And I should see the "div.bdd-menu-parent span.glyphicon.glyphicon-ok" element in the "content" region
    And I should see the link "BDD Child" in the "content" region
    When I click "BDD Child" in the "content" region
    Then I should see the heading "BDD menu child page"
      # Check that also active class has been added to child menu item when visiting current page.
    And I should see the "div.bdd-menu-parent a.active" element with the "data-image" attribute set to "ok" in the "content" region
    And I should see the "div.bdd-menu-parent span.glyphicon.glyphicon-ok" element in the "content" region

  @easy_breadcrumb
  Scenario: As a webmaster I want to modify an existing page
  and give it a short menu title to be used also as breadcrumb segment.
    Given I am logged in as a user with the "webmaster" role
    And I am viewing a "page" content in "published" status:
      | title | BDD my personal page content |
    And I should see "ENRD Home" in the "featured" region
    And I should see "BDD my personal page content" in the "featured" region
    When I click "New draft"
    And I check the box "Provide a menu link"
    And I fill in "Menu link title" with "BDD my page"
    And I select "Published" from "Moderation state"
    And I press "Save"
    Then I should see "BDD my page" in the "featured" region
