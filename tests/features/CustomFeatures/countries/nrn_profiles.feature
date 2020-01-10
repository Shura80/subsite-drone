@api @nrn_profiles
Feature: ENRD NRN Profiles

  This feature is aimed at creating the NRN Profile content type and its configurations for specific users: the "NRN Editor" role is allowed to modify only specific fields of the NRN Profile the user is related to. This feature also provides a hub page to reach the entire NRN Profiles list, which is dynamically fed.

  @anonymous @javascript
  Scenario: As Anonymous I can see the NRN Profile fields.
    Given I am an anonymous user
    And 'enrd_countries' terms:
      | name           | parent         |
      | European Union | Europe         |
      | BDD Italy      | European Union |

    And I am viewing a "rdp_information" content in "published" status:
      | title                            | BDD Custom Italian RDP information  |
      | field_enrd_rdp_info_country      | BDD Italy                           |

    And I am viewing a "nrn_profile" content in "published" status:
      | title                                        | BDD Italian NRN Profile                                 |
      | field_enrd_nrnp_brief_intro                  | BDD Brief Introductory Text                             |
      | field_enrd_nrnp_highlights                   | BDD Highlights                                          |
      | field_enrd_nrnp_activities                   | BDD Activities                                          |
      | field_enrd_nrnp_cooperation                  | BDD Italian interests                                   |
      | field_enrd_nrnp_country_page                 | BDD Custom Italian RDP information                      |
      | field_enrd_nrnp_organisation                 | BDD Sample Organisation                                 |
      | field_enrd_nrnp_phone                        | 123, 456, 789                                           |
      | field_enrd_nrnp_email:email                  | bdd-italy@bdd.com                                       |
      | field_enrd_nrnp_website                      | http://bdd-italian-nrn.com - http://bdd-italian-nrn.com |
      | field_enrd_nrnp_external_links               | BDD ext Italy - http://bdd-italy.com                    |
      | field_enrd_nrnp_objectives                   | BDD Italian NRN Objectives                              |
      | field_enrd_nrnp_membership                   | BDD Italian Membership                                  |
      | field_enrd_nrnp_nsu_rdp                      | BDD Italian NSU & RDP management                        |
      | field_enrd_nrnp_reg_repres                   | BDD Italian Representation                              |
      | field_enrd_nrnp_governance                   | BDD Italian Governance                                  |
      | field_enrd_nrnp_finan_resources              | BDD Italian Resources                                   |
      | field_enrd_nrnp_address:country              | IT                                                      |
      | :thoroughfare                                | Sample Street, 1                                        |
      | :premise                                     | Street 2 to complete Sample Street, 1                   |
      | :postal_code                                 | 00100                                                   |
      | :administrative_area                         | RM                                                      |
      | :locality                                    | Rome                                                    |
      | field_enrd_nrnp_social_media:service         | facebook, linkedin, twitter, youtube                    |
      | :url                                         | http://www.facebook.com/bdd-it, http://www.linkedin.com/bdd-it, http://www.twitter.com/bdd-it, http://www.youtube.com/bdd-it |

    And I create the following "field_enrd_nrnp_contact_persons" field collection
      | field_enrd_nrnp_contact_name         | John Doe                                    |
      | field_enrd_nrnp_contact_position     | BDD Italian Coordinator                     |
      | field_enrd_nrnp_contact_email:email  | john.doe@bdd-example.com                    |
      | field_enrd_nrnp_contact_phone        | +393333333333                               |

    Then I should see an ".icon-facebook" element
    Then I should see an ".icon-linkedin" element
    Then I should see an ".icon-twitter" element
    Then I should see an ".icon-youtube-play" element

    Then I should see the heading "BDD Italian NRN Profile"
    And I should see the text "BDD Brief Introductory Text"
    And I should see the text "BDD Highlights"
    And I should see the text "BDD Activities"
    And I should see the text "BDD Italian interests"
    And I should see the text "BDD Sample Organisation"
    And I should see the text "123"
    And I should see the text "456"
    And I should see the text "789"
    And I should see the text "bdd-italy@bdd.com"
    And I should see the link "Official NRN website"
    And I should see the link "BDD ext Italy"
    And I should see the text "John Doe"
    And I should see the text "BDD Italian Coordinator"
    And I should see the link "john.doe@bdd-example.com"
    And I should see the text "+393333333333"
    And I click "Objectives" in the "content" region
    And I should see the text "BDD Italian NRN Objectives"
    And I click "Membership" in the "content" region
    And I should see the text "BDD Italian Membership"
    And I click "NSU & RDP managment" in the "content" region
    And I should see the text "BDD Italian NSU & RDP management"
    And I click "Regional representation" in the "content" region
    And I should see the text "BDD Italian Representation"
    And I click "Governance" in the "content" region
    And I should see the text "BDD Italian Governance"
    And I click "Financial resources" in the "content" region
    And I should see the text "BDD Italian Resources"

  @nrn_editor
  Scenario: As NRN Editor I can modify only the node and the specific fields of the NRN Profile I am related to.
    Given 'enrd_countries' terms:
      | name           | parent         |
      | European Union | Europe         |
      | BDD Italy      | European Union |
    And an image "bdd-image.jpg" with the caption "BDD Image caption"

    And I am viewing an "rdp_information" content in "published" status:
      | title                            | BDD Italian RDP          |
      | field_enrd_rdp_info_country      | BDD Italy                |
    And I am viewing an "nrn_profile" content in "published" status:
      | title                            | BDD Italian NRN Profile                    |
      | field_enrd_nrnp_country_page     | BDD Italian RDP                            |
      | field_enrd_nrnp_address:country  | IT                                         |
      | :thoroughfare                    | Sample Street, 1                           |
      | :postal_code                     | 00100                                      |
      | :administrative_area             | RM                                         |
      | :locality                        | Rome                                       |
      | field_enrd_nrnp_logo             | bdd-image.jpg                              |
    And I create the following "field_enrd_nrnp_contact_persons" field collection
      | field_enrd_nrnp_contact_name         | John Doe                               |
      | field_enrd_nrnp_contact_position     | BDD Italian NRN Profile Coordinator    |
      | field_enrd_nrnp_contact_email:email  | john.doe@bdd-example.com               |

    Given I am logged in as a user with the "NRN Editor" roles and I have the following fields:
      | mail                        | bdd-nrn-editor@example.com |
      | field_enrd_nrnp_access_node | BDD Italian NRN Profile    |
    # An NRN Editor should NOT be able to edit an NRN Profile to which he is not related.
    When I am viewing an "nrn_profile" content in "published" status:
      | title                     | BDD Spanish Profile  |
    Then I should not see the link "Edit draft"
    # As NRN Editor I should not be able to create an NRN Profile.
    And I go to "node/add/nrn-profile"
    Then I should get a "403" HTTP response

    # An NRN Editor should be able to access only specific NRN Profile fields.
    And I am at "networking/nrn-profiles/bdd-italian-nrn-profile"
    And I click "New draft"
    And I fill in "Highlights" with "BDD NRN Highlights"
    And I fill in "Activities" with "BDD NRN Activities"
    And I fill in "Cooperation interests" with "BDD NRN Cooperation interests"
    And I fill in "Full name of organisation" with "BDD NRN Full name of organisation"
    And I fill in "Address 2" with "Street 2"
    And I fill in "field_enrd_nrnp_phone[und][0][value]" with "+393333133323"
    And I fill in "Email address" with "bdd-nrn-addr@bdd.com"
    And I fill in "field_enrd_nrnp_contact_persons[und][0][field_enrd_nrnp_contact_phone][und][0][value]" with "+3931245678"
    And I fill in "field_enrd_nrnp_website[und][0][url]" with "http://bdd-nrn-editor.com"
    And I fill in "field_enrd_nrnp_external_links[en][0][title]" with "External link 1"
    And I fill in "field_enrd_nrnp_external_links[en][0][url]" with "http://bdd-ext-nrn-editor.com"
    And I fill in "field_enrd_nrnp_social_media[und][social_buttons][element_0][url]" with "http://www.facebook.com/edited-nrn"

    # I should not see the "View changes" button.
    But I should not see the button "View changes"

    # I can access Media fields.
    But I should see a ".field-name-field-enrd-nrnp-documents" element
    And I should see "Attach documents" in the ".field-name-field-enrd-nrnp-documents" element
    But I should see a ".field-name-field-enrd-nrnp-image" element
    But I should see a ".field-name-field-enrd-nrnp-video" element
    # I should not be able to modify Administration fields.
    But I should not see a ".form-item-title" element
    But I should not see a ".field-name-field-enrd-nrnp-brief-intro" element
    And I should not see a ".field-name-field-enrd-nrnp-country-page" element
    And I should not see a ".field-name-field-enrd-nrnp-logo" element
    And I should not see a ".field-name-field-enrd-nrnp-objectives" element
    And I should not see a ".field-name-field-enrd-nrnp-membership" element
    And I should not see a ".field-name-field-enrd-nrnp-nsu-rdp" element
    And I should not see a ".field-name-field-enrd-nrnp-reg-repres" element
    And I should not see a ".field-name-field-enrd-nrnp-governance" element
    And I should not see a ".field-name-field-enrd-nrnp-finan-resources" element

    Then I check "I confirm that the data I have added in my NRN profile can be published by the ENRD CP."
    And I should see the text "Please double check the submitted information before proceeding. After checking this box and saving your changes you will not be able to create a new or edit this draft until the revision has been approved/rejected by the ENRD CP administrator. If you want to return and edit your draft save your draft without checking this box"
    And I check "By checking this box, you acknowledge that you have read and understood the European Commission's legal notice."
    And I press "Save"

    Then I should see the following success messages:
      | success messages                                      |
      | NRN Profile BDD Italian NRN Profile has been updated. |

  @nrn_editor @admin @emails @workflow
  Scenario: As Administrator and NRN Editor I want to be notified: if an nrn editor creates a new draft from a published
    NRN Profile and requests its publication, if an NRN Editor creates a new draft and asks for its publication and if
    and Administrator rejects the NRN Profile for which I requested publication.
    And 'enrd_countries' terms:
      | name           | parent         |
      | European Union | Europe         |
      | BDD Ireland    | European Union |
    And an image "bdd-image.jpg" with the caption "BDD Image caption"

    And I am viewing an "rdp_information" content in "published" status:
      | title                            | BDD Irish RDP          |
      | field_enrd_rdp_info_country      | BDD Ireland            |
    And I am viewing an "nrn_profile" content in "published" status:
      | title                            | BDD Irish NRN Profile  |
      | field_enrd_nrnp_brief_intro      | BDD Brief Intro Text   |
      | field_enrd_nrnp_country_page     | BDD Irish RDP          |
      | field_enrd_nrnp_address:country  | IE                     |
      | :thoroughfare                    | Sample Street, 1       |
      | :locality                        | Dublin                 |
      | field_enrd_nrnp_phone            | +3533333333333         |
      | field_enrd_nrnp_email:email      | bdd-nrn-editor@bdd.com |
      | field_enrd_nrnp_website          | http://bdd-example.com - http://bdd-example.com |
      | field_enrd_nrnp_logo             | bdd-image.jpg          |
    And I create the following "field_enrd_nrnp_contact_persons" field collection
      | field_enrd_nrnp_contact_name         | John Doe           |
      | field_enrd_nrnp_contact_email:email  | john.doe@bdd.com   |

    Given the test email system is enabled
    Given I am logged in as a user with the "NRN Editor" role and I have the following fields:
      | mail                        | bdd-nrn-editor@example.com |
      | field_enrd_nrnp_access_node | BDD Irish NRN Profile      |
    # Published -> Ready to be published.
    When I click "BDD Irish NRN Profile"
    And I click "New draft"
    And I check "I confirm that the data I have added in my NRN profile can be published by the ENRD CP."
    And I check "By checking this box, you acknowledge that you have read and understood the European Commission's legal notice."
    And I press "Save"
    Then I should see "This draft version is the most recent revision of this NRN Profile, it has been submitted for publication and is currently under evaluation by the ENRD CP. You will be able to create a new draft again after the revision has been approved/rejected. If you want to contact the website administrator please sent an email to nrn-profiles@enrd.eu." in the ".workbench-info-block" element
    Then the email to "bdd-nrn-editor@example.com" should contain "ENRD NRN Profiles – NRN Profile sent for publication"
    And the email to "nrn-profiles@enrd.eu" should contain "NRN Profile update ready for publication"

    # An NRN Editor can ask for publishing from an "Ask for publishing" button.
    Given I am logged in as a user with the "administrator" role
    And I am at "admin/workbench/moderate-all"
    And I click "Change to Published" in the "BDD Irish NRN Profile" row
    # Draft -> Ready to be published.
    Given I am logged in as a user with the "NRN Editor" role and I have the following fields:
      | mail                        | bdd-test-nrn-editor@example.com |
      | field_enrd_nrnp_access_node | BDD Irish NRN Profile           |
    When I click "BDD Irish NRN Profile"
    And I click "New draft"
    And I check "By checking this box, you acknowledge that you have read and understood the European Commission's legal notice."
    And I press "Save"
    And I press "Ask for publishing"
    Then I should see the error message containing "You must agree with the EU Legal notice statement to proceed."
    And I check "By checking this box, you acknowledge that you have read and understood the European Commission's legal notice."
    And I press "Ask for publishing"
    And I follow "View published"
    Then I should see "A most recent revision of this NRN Profile has been submitted for publication and is currently under evaluation by the ENRD CP. You will be able to edit it again after the revision has been approved/rejected." in the ".workbench-info-block" element
    Then the email to "bdd-test-nrn-editor@example.com" should contain "ENRD NRN Profiles – NRN Profile sent for publication"
    And the email to "nrn-profiles@enrd.eu" should contain "NRN Profile update ready for publication"

    # Ready to be published -> Draft.
    Given users:
      | name                | mail                            | pass | roles      | field_enrd_nrnp_access_node |
      | bdd-john-doe-editor | bdd-john-doe-editor@example.com | test | NRN Editor | BDD Irish NRN Profile       |
    When I am logged in as a user with the "administrator" role
    And I am at "networking/nrn-profiles/bdd-irish-nrn-profile"
    And I follow "View draft"
    And I select "Draft" from "Moderation state"
    And I fill in "Moderation notes" with "Node rejected for lack of information"
    And I press "Apply"
    # As NRN Editor I want to be notified if an NRN Profile ready to be published has been rejected.
    Then the email to "bdd-john-doe-editor@example.com" should contain "ENRD NRN Profile – NRN Profile rejected"
    And the email to "bdd-john-doe-editor@example.com" should contain "Node rejected for lack of information"
    # As NRN Editor I should see the "Rejection reason" in the Workbench block.
    When I am logged in as "bdd-john-doe-editor"
    And I click "BDD Irish NRN Profile"
    And I follow "View draft"
    Then I should not see "This draft version is the most recent revision of this NRN Profile, it has been submitted for publication and is currently under evaluation by the ENRD CP. You will be able to create a new draft again after the revision has been approved/rejected. If you want to contact the website administrator please sent an email to nrn-profiles@enrd.eu." in the ".workbench-info-block" element
    Then I should see "Moderation notes: Node rejected for lack of information" in the ".workbench-info-block" element

  @nrn_editor @emails @workflow
  Scenario: As NRN Editor I want to be notified if an NRN Profile ready to be published has been published.
    Given I am viewing an "nrn_profile" content in "ready_to_be_published" status:
      | title                        | BDD Ready published NRN Profile  |
    And I am logged in as a user with the "NRN Editor" role and I have the following fields:
      | mail                        | bdd-user-nrn-editor@example.com |
      | field_enrd_nrnp_access_node | BDD Ready published NRN Profile |
    And the test email system is enabled
      # Ready to be published -> Published.
    And I am logged in as a user with the "administrator" role
    And I am at "admin/workbench/moderate-all"
    And I click "Change to Published" in the "BDD Ready published NRN Profile" row
    Then the email to "bdd-user-nrn-editor@example.com" should contain "ENRD NRN Profiles – NRN Profile published"

  @anonymous
  Scenario: As Anonymous I want to visit the NRN Profiles dynamic page to see the list of active NRN Profiles.
    Given I am viewing an "nrn_profile" content in "published" status:
      | title                         | BDD NRN Profile in hub page  |
      | field_enrd_nrnp_brief_intro   | BDD Brief Introductory Text  |
    Given I am viewing an "nrn_profile" content in "draft" status:
      | title                         | BDD NRN Profile Draft in hub page  |
    Given I am logged in as a user with the "administrator" role
    And I am at "node/add/page"
    And I fill in "title_field[en][0][value]" with "NRN Profiles"
    And I uncheck "Generate automatic URL alias"
    And I fill in "URL alias" with "networking/nrn-profiles"
    And I select "Published" from "Moderation state"
    And I press "Save"
    Then I should see the heading "BDD NRN Profile in hub page" in the "bottom content" region
    And I should see the text "BDD Brief Introductory Text" in the "bottom content" region
    But I should not see "BDD NRN Profile Draft in hub page" in the "bottom content" region

  @admin @javascript
  Scenario: As Administrator I manage the NRN editors trough administrative panels.
    Given I am viewing an "nrn_profile" content in "published" status:
      | title                     | BDD France NRN Profile  |
    And users:
      | name                | mail                            | pass | roles      | field_enrd_nrnp_access_node |
      | bdd-john-doe-editor | bdd-john-doe-editor@example.com | test | NRN Editor | BDD France NRN Profile      |
    And I am logged in as a user with the "administrator" role
    When I am at "admin/enrd/nrn-profiles/editors"
    Then I should see "NRN Profile page editors"
    And I should see the link "bdd-john-doe-editor"
    When I check the box "edit-views-bulk-operations-0"
    And I press "Remove NRN Editor"
    And I press the "Confirm" button
    And I wait for the batch job to finish
    Then I should not see the link "bdd-john-doe-editor"
    And I should see the following success messages:
      | success messages                       |
      | Performed Remove NRN Editor on 1 item. |
