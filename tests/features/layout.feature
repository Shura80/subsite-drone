@api
Feature: Test visual layouts of the site

  @homepage @search_api_node
  # Homepage layout.
  Scenario: Check homepage layout
    Given I am an anonymous user
    # Add content to bring up some homepage blocks in clean environment.
    # Add at least a top news to show Spotlight block in clean environment.
    And I am viewing a "news" content in "published" status:
      | title          | BDD Home news |
      | field_top_news | top           |
      | language       | und           |
    # Add at least an event to show homepage latest events block in clean environment.
    And I am viewing an "event" content in "published" status:
      | title            | BDD Home event   |
      | field_event_date | now - now +1week |
      | language         | und              |
    # Add at least a project to show homepage latest projects block in clean environment.
    And I am viewing a "project" content in "published" status:
      | title    | BDD home project |
      | language | und              |
    And I send site contents to the Search API node index
    And I am on the homepage
    # Service links from EC_Resp base theme header region.
    Then I should see the link "Legal notice" in the "header_right"
    And I should see the link "Cookies" in the "header_right"
    And I should see the link "Contact on Europa" in the "header_right"
    And I should see an "#block-search-form" element
    And I should see "Search" in the "form#search-block-form" element
    And I should see the link "My Account" in the "header_right"
    # Main menu links.
    And I should see the link "EIP-AGRI Projects" in the "featured"
    And I should see the link "Find" in the "featured"
    # "Find" 2nd level children items.
    And I should see the link "Projects" in the "featured"
    And I should see the link "Funding" in the "featured"
    And I should see the link "Research needs" in the "featured"
    And I should see the link "Project ideas" in the "featured"
    And I should see the link "People" in the "featured"
    And I should see the link "Online resources" in the "featured"
    # Other main menu items.
    And I should see the link "Events" in the "featured"
    And I should see the link "News" in the "featured"
    And I should see the link "Publications" in the "featured"
    # Content Top.
    And I should see an "#block-agri-core-agri-core-twitter-feeds" element
    And I should see "Join the conversation" in the "content_top"
    And I should see an ".menu-link-call-to-action" element
    And I should see an ".menu-link-user-register" element
    And I should see the link "Register to the EIP‑AGRI website" in the "content_top"
    And I should see an ".menu-link-subscribe-newsletter" element
    And I should see the link "Subscribe to the EIP‑AGRI newsletter" in the "content_top"
    And I should see an ".menu-link-agrinnovation-magazine" element
    And I should see the link "Read Agrinnovation magazine" in the "content_top"
    # Content Top Left.
    And I should see an "#block-views-core-spotlight-block" element
    And I should see "Spotlight news" in the "content_top_left"
    And I should see the link "View all news" in the "content_top_left"
    # Content Top Right.
    And I should see an "#block-views-events-blocks-event-home-block" element
    And I should see "Upcoming events" in the "content_top_right"
    And I should see the link "View all events" in the "content_top_right"
    # Content Bottom
    And I should see an "#block-bean-funding-opportunities" element
    And I should see an "#block-bean-enrd" element
    And I should see an "#block-bean-videos" element
    And I should see an "#block-views-2be5cc485f630726ac16a016e1ccfdde" element
    And I should see an "#block-bean-digital-agriculture" element
    And I should see an "#block-bean-find-people" element
    # Content Bottom First
    And I should see "Latest Projects" in the "content_bottom_first"
    # Content Bottom Second
    And I should see the link "Funding opportunities" in the "content_bottom_second"
    And I should see the link "All funding opportunities" in the "content_bottom_second"
    And I should see the link "Digital agriculture" in the "content_bottom_second"
    And I should see the link "Go to digitising agriculture" in the "content_bottom_second"
    # Content Bottom Third
    And I should see the link "Videos" in the "content_bottom_third"
    And I should see the link "Video gallery" in the "content_bottom_third"
    And I should see the link "Find people" in the "content_bottom_third"
    And I should see the link "Join the EIP-AGRI network" in the "content_bottom_third"
    And I should see the link "Go to ENRD website" in the "content_bottom_third"
    # Footer logo, contact email link & Social links.
    And I should see an "#block-agri-core-footer-ec-logo" element
    And I should see "Funded by" in the "footer"
    And I should see an "#block-agri-core-footer-contacts" element
    And I should see the link "servicepoint@eip-agri.eu" in the "footer"
    And I should see an "#block-menu-menu-social-footer" element
    And I should see an ".youtube-icon" element
    And I should see an ".linkedin-icon" element
    And I should see an ".twitter-icon" element
    And I should see the link "Youtube" in the "footer"
    And I should see the link "LinkedIn" in the "footer"
    And I should see the link "Twitter" in the "footer"

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
