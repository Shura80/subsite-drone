@api @enrd-sfr @enrd-ruralstory
Feature: ENRD Rural Story Form
  This feature consists of a form that allows users to send their story to the Contact Points of ENRD.

  @emails
  Scenario: Check automatic emails generated when the form is submitted.
    Given I am logged in as a user with the "authenticated" role
    And "enrd_countries" terms:
      | name        | parent         |
      | BDD Belgium | European Union |
    And "enrd_ruralstory_topics" terms:
      | name                  |
      | BDD Rural story Topic |
    And a document "bdd-file.pdf"
    And I create the following "enrd_sfr" entity of type "enrd_ruralstory":
      | field_enrd_ruralstory_subject     | BDD Rural Story                      |
      | field_enrd_ruralstory_topic       | BDD Rural story Topic                |
      | field_enrd_ruralstory_country     | BDD Belgium                          |
      | field_enrd_ruralstory_region      | Flanders                             |
      | field_enrd_ruralstory_title       | Mr                                   |
      | field_enrd_ruralstory_name        | John                                 |
      | field_enrd_ruralstory_surname     | Doe                                  |
      | field_enrd_ruralstory_email:email | jdoe@example.com                     |
      | field_enrd_ruralstory_links       | BDD Begium link - http://example.com |
      | field_enrd_ruralstory_files       | bdd-file.pdf                         |
      | field_enrd_ruralstory_org         | BDD Rural Story Org                  |
      | field_enrd_ruralstory_short_desc  | Lorem ipsum sin amet                 |
      | field_enrd_ruralstory_tel         | +32020123456789                      |
    Then the email to "rural-stories@enrd.eu" should contain "New Rural Story submission"
    And the email to "rural-stories@enrd.eu" should contain "Subject: BDD Rural Story"
    And the email to "rural-stories@enrd.eu" should contain "Name: John"
    And the email to "rural-stories@enrd.eu" should contain "Surname: Doe"
    And the email to "rural-stories@enrd.eu" should contain "You can check further information on the “Share Your Story” submission page"
    And the email to "jdoe@example.com" should contain "Rural Story submission on ENRD website"
    And the email to "jdoe@example.com" should contain "Theme / topic: BDD Rural story Topic"
    And the email to "jdoe@example.com" should contain "You have succesfully submitted the following information on the ENRD website"
    And the email to "jdoe@example.com" should contain "You have submitted 1 relevant link(s)"
    And the email to "jdoe@example.com" should contain "You have submitted 1 attached file(s)"

  Scenario: Check validation errors and check that authenticated users can submit Rural Story Form and get a visual and email confirmations.
    Given I am an anonymous user
    And I am at "enrd-sfr/add/enrd-ruralstory"
    Then I should see the heading "Share your Rural Story"
    And I press "Send your story"
    Then I should see the following error messages:
      | error messages                                                      |
      | Country field is required.                                          |
      | Email field is required.                                            |
      | Name field is required.                                             |
      | Short description of your story field is required.                  |
      | Subject field is required.                                          |
      | Surname field is required.                                          |
      | Theme / topic field is required.                                    |
      | You must agree with the ENRD CP Authorization Statement to proceed. |
      | You must agree with the ENRD Privacy Statement to proceed.          |
      | You must agree with the Collection of Data Statement to proceed.    |

  @enrd-ruralstory-form @privacy
  Scenario: Check that an authenticated user can use the Rural Story form
  to add a new submission.
    Given I am logged in as a user with the "authenticated" role
    And 'enrd_countries' terms:
      | name        | parent         |
      | BDD Belgium | European Union |
    And "enrd_ruralstory_topics" terms:
      | name                  |
      | BDD Rural story Topic |
    And I am at "enrd-sfr/add/enrd-ruralstory?topic=bdd rural story topic"
    And I fill in "Subject" with "BDD Rural Story"
    And I select "BDD Belgium" from "Country"
    And I fill in "Region" with "Flanders"
    And I fill in "Organisation" with "BDD Rural Story Org"
    And I select "Mr" from "Title"
    And I fill in "Name" with "John"
    And I fill in "Surname" with "Doe"
    And I fill in "Email" with "jdoe@example.com"
    And I fill in "Tel." with "+32020123456789"
    And I fill in "Short description of your story " with "Lorem ipsum sin amet."
    And I fill in "edit-field-enrd-ruralstory-links-und-0-url" with "http://example.com"
    And I attach the file "bdd-file.pdf" to "edit-field-enrd-ruralstory-files-und-0-upload"
    And I press "Upload"
    And I check the box "enrd_ruralstory_authorize_notice"
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I press "Send your story"
    Then I should see "Your rural story has been submitted correctly."
    And I press "OK"

  @javascript
  Scenario: Manage form submissions in the report page with a ruralstory submission manager.
    Given I am logged in as a user with the "rural story submissions manager" role
    And "enrd_countries" terms:
      | name        | parent         |
      | BDD Belgium | European Union |
    And "enrd_ruralstory_topics" terms:
      | name                  |
      | BDD Rural story Topic |
    And a document "bdd-file.pdf"
    And I am viewing the "enrd_sfr" entity of type "enrd_ruralstory":
      | field_enrd_ruralstory_subject     | BDD Rural Story                      |
      | field_enrd_ruralstory_topic       | BDD Rural story Topic                |
      | field_enrd_ruralstory_country     | BDD Belgium                          |
      | field_enrd_ruralstory_region      | Flanders                             |
      | field_enrd_ruralstory_title       | Mr                                   |
      | field_enrd_ruralstory_name        | John                                 |
      | field_enrd_ruralstory_surname     | Doe                                  |
      | field_enrd_ruralstory_email:email | jdoe@example.com                     |
      | field_enrd_ruralstory_links       | BDD Begium link - http://example.com |
      | field_enrd_ruralstory_files       | bdd-file.pdf                         |
      | field_enrd_ruralstory_org         | BDD Rural Story Org                  |
      | field_enrd_ruralstory_short_desc  | Lorem ipsum sin amet                 |
      | field_enrd_ruralstory_tel         | +32020123456789                      |
    # Content region submission data
    Then I should see "About the Rural Story" in the content
    And I should see "BDD Rural Story" in the content
    And I should see "BDD Rural story Topic" in the content
    And I should see "Lorem ipsum sin amet" in the content
    And I should see the link "http://example.com" in the content
    And I should see the link "bdd-file.pdf" in the content

    # Personal information submission data
    And I should see "Personal information" in the content
    And I should see "Mr" in the content
    And I should see "John" in the content
    And I should see "Doe" in the content
    And I should see the link "jdoe@example.com" in the content
    And I should see "+32020123456789" in the content
    And I should see "BDD Rural Story Org" in the content

    # Geographical information data
    And I should see "Geographical information" in the content
    And I should see "BDD Belgium" in the content
    And I should see "Flanders" in the content

    # Check flag functionality report view.
    And I should see the link "Set status" in the content
    When I press "Back to Submissions Report"
    Then I am at "admin/enrd/enrd-sfr-ruralstory"
    # Check operations permissions.
    And I should see the button "Set status"
    And I should see the button "Remove status"
    But I should not see the button "Delete"
    When I fill in "Free-text search" with "BDD"
    And I press "Apply"
    And I check the box "edit-views-bulk-operations-0"
    And I press "Set status"
    And I select "eligible" from "edit-status"
    And I press the "Next" button
    And I press the "Confirm" button
    And I wait for AJAX to finish
    Then I should see the following success messages:
      | success messages                |
      | Performed Set status on 1 item. |
    And I should see "eligible" in the "BDD Rural Story" row
    When I check the box "edit-views-bulk-operations-0"
    # Remove status
    And I press "Remove status"
    And I press the "Confirm" button
    And I wait for AJAX to finish
    Then I should see the following success messages:
      | success messages                   |
      | Performed Remove status on 1 item. |
    And I should not see "eligible" in the "BDD Rural Story" row

    # Check flag functionality on Submission detail page.
    When I click "BDD Rural Story"
    And I click "Set status"
    And I wait
    And I click "eligible"
    And I wait for AJAX to finish
    Then I should see "eligible" in the content
    And I should see the link "Remove status"
    # Remove status.
    # When I click "Remove status"
    # And I wait for AJAX to finish
    # Then I should not see "eligible" in the content
    # And I should see the link "Set status"

  @javascript @webmaster
  Scenario: Check that webmaster users can also delete submission items.
    Given I am logged in as a user with the "webmaster" role
    And "enrd_ruralstory_topics" terms:
      | name                  |
      | BDD Rural story Topic |
    And I create the following "enrd_sfr" entity of type "enrd_ruralstory":
      | field_enrd_ruralstory_subject | BDD Rural Story       |
      | field_enrd_ruralstory_topic   | BDD Rural story Topic |
    And I am at "admin/enrd/enrd-sfr-ruralstory"
    # Check operations permissions.
    Then I should see the button "Set status"
    And I should see the button "Remove status"
    And I should see the button "Delete"
    When I fill in "Free-text search" with "BDD"
    And I set the chosen element "field_enrd_ruralstory_topic_tid[]" to "BDD Rural story Topic"
    And I press "Apply"
    And I check the box "edit-views-bulk-operations-0"
    And I press "Delete"
    And I press "Confirm"
    And I wait for AJAX to finish
    Then I should see the following success messages:
      | success messages            |
      | Performed Delete on 1 item. |

  @webmaster
  Scenario: Check that a Webmaster can see a warning message listing the
    referenced rural stories before deleting a "ENRD Rural Story Topics" term.
    Given I am logged in as a user with the "webmaster" role
    And "enrd_ruralstory_topics" terms:
      | name                  |
      | BDD Rural story Topic |
    And I create the following "enrd_sfr" entity of type "enrd_ruralstory":
      | field_enrd_ruralstory_subject | BDD Rural Story       |
      | field_enrd_ruralstory_topic   | BDD Rural story Topic |
    When I am at "admin/structure/taxonomy/enrd_ruralstory_topics"
    And I click "edit" in the "BDD Rural story Topic" row
    And I press the "Delete" button
    Then I should see the text "Caution: this term is being referenced by the following rural story"
    And I should see the link "BDD Rural Story"
