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

  @javascript @administrator @filters
  Scenario: Insert links in content textareas through CKEditor "Insert internal links" functionality
    Given I am logged in as a user with the "administrator" role
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
    When I am logged in as a "administrator"
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

  @admin @clean
  Scenario: As Admin I want to be able to display a sitewide disclaimer in the Footer Top region.
    Given I am logged in as a user with the "administrator" role
    And I am at "block/footertopdisclaimer/edit"
    And I fill in "Block Body" with "<div class=\"alert alert-warning\" role=\"alert\" style=\"margin:0; padding:0.6em 1em; font-size:10px;word-spacing: -0.5px;\">This is a Footer Top disclaimer.</div>"
    And I press "Save"
    Given I am an anonymous user
    Then I should see "This is a Footer Top disclaimer." in the "footer top" region

  @footer @last-update-info
  Scenario: As user I should receive different messages in the footer content block
  depending on what I am watching (node, user, file, view, solr page, junction page, etc...).
    Given I am logged in as a user with the "administrator" role
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
    When I am at "admin/people"
    And I fill in "Username" with "bdd-user-footer"
    And I press "Apply"
    And I click "edit" in the "bdd-user-footer" row
    Then I should see "Last accessed: never" in the footer
    And I should not see "Last updated:" in the footer
    # Taxonomy terms.
    When I am at "tags/bdd-keyword"
    Then I should see "Last updated:" in the footer
