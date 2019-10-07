@api
Feature: Test visual layouts of the site

  @homepage
  # Homepage layout
  Scenario: Check homepage layout
    Given I am an anonymous user
    And I am on the homepage
    # Service links from EC_Resp base theme header region
    Then I should see the link "Legal notice"
    And I should see the link "Cookies" in the "header"
    And I should see the link "Contact on Europa" in the "header"
    And I should see the link "My Account" in the "header"
    And I should see an "#block-search-form" element
    And I should see "Search" in the "form#search-block-form" element
    # Main menu links
    And I should see the link "Find" in the "featured"
    # "Find" 2nd level children items.
    And I should see the link "Projects" in the "featured"
    And I should see the link "Funding" in the "featured"
    And I should see the link "Research needs" in the "featured"
    And I should see the link "Project Ideas" in the "featured"
    And I should see the link "People" in the "featured"
    And I should see the link "Online resources" in the "featured"
    # Other main menu items
    And I should see the link "Events" in the "featured"
    And I should see the link "News" in the "featured"
    And I should see the link "Publications" in the "featured"
    # Content
    And I should see "The one-stop-shop for Agricultural Innovation in Europe" in the "content_top_left"
    And I should see "Share with us" in the "content_top_left"
    And I should see "Search and find" in the "content_top_left"
    And I should see "Focus on" in the "content_top_left"
    And I should see "Deepen your knowledge" in the "content_top_left"
    And I should see "Stay up to date" in the "content_top_left"
    And I should see "My Account" in the "content_top_left"
    # Right sidebar blocks
    And I should see 'Register or login to "EIP-AGRI"' in the "sidebar_right"
    And I should see 'Ask a question or provide feedback' in the "sidebar_right"
    # Footer contact email link & Social links
    And I should see the text "Follow us" in the "footer"

  @profile
  # User login page
  Scenario: Check login page layout and links
    Given I am an anonymous user
    And I am on "/user"
    Then I should not see the link "Create new account"
    But I should see "Register/Login with EU Login" in the "content"
    But I should see "Login with EIP-AGRI account" in the "content"
    And I should see the button "Log in"

  @profile
  Scenario: Check logout link for authenticated users.
    Given I am logged in as a user with the "contributor" role
    And I am on "/user"
    Then I should see "Log out"

  @profile
  # User profile edit form - Contributor
  Scenario: Check user profile page layout - contributor role
    Given I am logged in as a user with the "contributor" role
    When I am on "/user"
    # User menu block
    Then I should see "User menu" in the "sidebar_left"
    And I should see the link "Find people" in the "sidebar_left"
    And I should see the link "My content" in the "sidebar_left"
    And I should see the link "My form submissions" in the "sidebar_left"
    # Action menu block
    And I should see "Action menu" in the "sidebar_left"
    And I should see the link "Add content" in the "sidebar_left"
    And I should see the link "Log out" in the "sidebar_left"
    # Main content blocks
    And I should see "Funding opportunities"
    And I should see "News and events"
    And I should see "People"
    # Links in upper tabs
    And I should see the link "Edit"
    And I should see the link "Subscriptions"
    And I should see the link "Saved searches"

  @profile
  # User profile edit form - Editor
  Scenario: Check user profile page layout - editor role
    Given I am logged in as a user with the "editor" role
    When I am on "/user"
    # Action menu block: editors has more options on this block
    Then I should see "Action menu" in the "sidebar_left"
    And I should see the link "Categories management" in the "sidebar_left"
    And I should see the link "Menu management" in the "sidebar_left"
