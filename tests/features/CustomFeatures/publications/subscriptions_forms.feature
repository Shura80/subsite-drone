@api @sfr-pub
Feature: ENRD Publication Subscriptions forms.
  This Feature is aimed at allowing any users to fill in a form in order to subscribe to both CP and Evaluation publications and to send an unsubscription / modification email to the respective webmaster in charge.
  It also provides allowed users with several administration interfaces listing the form requests of a certain type: CP subscriptions, EHD subscriptions, CP contact requests and EHD contact requests. From these interfaces, admins can delete (bulk operation) or export the
  available requests.

  @anonymous @enrd-sfr @subscribe @cp @ehd @clean
  Scenario: As Anonymous I want to access the: Publications, Evaluation Publications & Newsletter
  Subscriptions pages from the left sidebar "Subscribe" menu links.
    Given I am an anonymous user
    When I am on the homepage
    Then I should see the heading "Subscribe" in the "left sidebar" region
    When I click "Publications" in the "left sidebar" region
    Then I should see the heading "Subscribe to publications"
    When I click "Evaluation Publications" in the "left sidebar" region
    Then I should see the heading "Subscribe to Evaluation publications"
    And I should see "Newsletter" in the "section#block-menu-menu-enrd-sfr-pub-subscribe" element

  @anonymous @enrd-sfr @subscribe @cp @privacy
  Scenario: As Anonymous I want to be able to subscribe to CP publications.
    Given I am an anonymous user
    And "enrd_publications" terms:
      | name                | field_enrd_publications_ext_link                                   |
      | BDD EU Rural Review | Subscribe to Publications - enrd-sfr/add/enrd-sfr-pub-subscribe-cp |
    And I am viewing a "publication" content in "published" status:
      | title                       | BDD CP Publication  |
      | language                    | en                  |
      | field_enrd_publication_type | BDD EU Rural Review |
    And I am viewing a "page" content in "published" status:
      | title    | Publications |
      | language | en           |
    # I can access from the Publications search page.
    When I am at "publications/search"
    And I click "Subscribe to Publications"
    Then I should see the heading "Subscribe to publications"
    And I should see "Fill in the form below to request subscription to ENRD publications."
    And I should see "By checking this box, you acknowledge that you have read and understood the ENRD Privacy Statement."
    And I should see "I agree that my data may be collected and used for the purposes mentioned in the privacy statement."
    And I should see "If you want to subscribe to the Newsletter, please go to the ENRD Newsletter subscription page."
    And I should see "If you want to unsubscribe or modify your subscriptions, please send your request to the ENRD Contact Point."
    # I can access from a Publication page.
    When I am at "publications/bdd-cp-publication"
    And I should see "Subscribe to Publications" in the ".ds-side" element
    And I click "Subscribe to Publications"
    Then I should see the heading "Subscribe to publications"
    # I can access from the main Publications page.
    When I am at "publications"
    And I click "Subscribe to Publications"
    Then I should see the heading "Subscribe to publications"

  @anonymous @enrd-sfr @subscribe @ehd @clean @privacy
  Scenario: As Anonymous I want to be able to subscribe to EHD publications.
    Given I am an anonymous user
    # I can access from an Evaluation Publication page.
    And I am viewing a "publication_ehd" content in "published" status:
      | title    | BDD EHD Publication |
      | language | en                  |
    When I am at "evaluation/publications/bdd-ehd-publication"
    And I click "Subscribe to Evaluation Publications" in the "right sidebar" region
    Then I should see the heading "Subscribe to Evaluation publications"
    # I can access from the Rural Evaluation News page.
    And I am viewing a "publication_ehd" content in "published" status:
      | title    | Evaluation Helpdesk's Publications: Rural Evaluation NEWS |
      | language | en                                                        |
    When I am at "evaluation/publications/evaluation-helpdesks-publications-rural-evaluation-news"
    And I click "Subscribe to Evaluation Publications" in the "right sidebar" region
    Then I should see the heading "Subscribe to Evaluation publications"
    # I can access from the main Publications page.
    And I am viewing a "page" content in "published" status:
      | title    | Publications |
      | language | en           |
    When I am at "publications"
    And I click "Subscribe to Publications"
    Then I should see the heading "Subscribe to publications"
    # I can access from the Evaluation Publications search page.
    When I am at "evaluation/publications"
    And I click "Subscribe to Evaluation Publications"
    Then I should see the heading "Subscribe to Evaluation publications"
    And I should see "Fill in the form below to request subscription to Evaluation publications."
    And I should see "By checking this box, you acknowledge that you have read and understood the ENRD Privacy Statement."
    And I should see "I agree that my data may be collected and used for the purposes mentioned in the privacy statement."
    And I should see "If you want to unsubscribe or modify your subscription data please contact the Evaluation Helpdesk."

  @anonymous @enrd-sfr @contact @cp
  Scenario: As Anonymous I want to be able to unsubscribe from CP publications.
    Given I am an anonymous user
    When I am at "publications/search"
    And I click "Subscribe to Publications"
    And I click "send your request to the ENRD Contact Point"
    Then I should see the heading "Unsubscribe / modify your subscription to publications"
    And I should see "Fill in the form below to request to unsubscribe or modify your subscription to ENRD publications."

  @anonymous @enrd-sfr @contact @ehd
  Scenario: As Anonymous I want to be able to unsubscribe from EHD publications.
    Given I am an anonymous user
    When I am at "evaluation/publications"
    And I click "Subscribe to Evaluation Publications"
    And I click "contact the Evaluation Helpdesk"
    Then I should see the heading "Unsubscribe / modify your subscription to Evaluation publications"
    And I should see "Fill in the form below to request to unsubscribe or modify your subscription to Evaluation publications."

  @authenticated @javascript @enrd-sfr @subscribe @cp @privacy
  Scenario: As Authenticated I want to fill in the form to subscribe to CP publications, and I get Name, Surname and
  Email already pre-filled.
  I should not get a confirmation message to validate the e-mail (and the subscription request in turn).
    Given I am logged in as a user with the "authenticated user" role and I have the following fields:
      | mail            | john.doe@example.com |
      | field_firstname | John                     |
      | field_lastname  | Doe                      |
    # I can access from the Publications search page.
    When I am at "publications/search"
    And I click "Subscribe to Publications"
    # I should see Contact details, Your choice of publications & Delivery address field group labels.
    Then I should see "Contact details" in the ".group-contact-details" element
    And I should see "Your choice of publications" in the ".group-public-choices" element
    # Delivery Address is visible only if Paper is checked.
    And I should not see "Delivery address" in the ".group-delivery-address" element
    And I check "Paper version"
    Then I should see "Delivery address" in the ".group-delivery-address" element
    # Name, Organisation, Address Line 1 & Address Line 2 should have a maxlength description.
    Then I should see "Name + Surname should be maximum 35 characters." in the ".form-item-field-enrd-sfr-pub-subcp-name-und-0-value" element
    And I should see "Maximum 35 characters." in the ".form-item-field-enrd-sfr-pub-subcp-org-und-0-value" element
    And I check "Paper version"
    And I should see "Maximum 35 characters." in the ".form-item-field-enrd-sfr-pub-subcp-addr-und-0-thoroughfare" element
    And I should see "Maximum 35 characters." in the ".form-item-field-enrd-sfr-pub-subcp-addr-und-0-premise" element
    # Form filling.
    And I select "Mr" from "Title"
    And I fill in "Organisation" with "John Doe's Corporation"
    And I select "EU Rural Review" from "Type of publication"
    And I check the box "Paper version"
    And I select "EN" from "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_lng_cop][und][0][first]"
    And I select "1" from "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_lng_cop][und][0][second]"
    And I check the box "Electronic version"
    And I set the chosen element "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_el_lang][und][]" to "EN"
    And I select "Italy" from "Country"
    And I wait for AJAX to finish
    And I fill in "Address Line 1" with "Sample Street, 1"
    And I fill in "Address Line 2" with "Street 2 to complete Sample Street, 1"
    And I fill in "Postal code " with "00100"
    And I fill in "City" with "Rome"
    And I select "Roma" from "Province"
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I press the "Send request" button
    Then I should see the message "Your submission request has been forwarded correctly."
    But I should not see the message "We have sent a confirmation email to the email address you have specified. Please open it and click on the link in order to finalize the request you have just submitted."
    # Test the destination parameter in the url.
    And I should see the heading "Search Publications"

    # Test "Remove publication" button next to Type of pub. selects.
    When I am at "enrd-sfr/add/enrd-sfr-pub-subscribe-cp"
    And I select "EU Rural Review" from "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_typepub][und]"
    And I check the box "Electronic version"
    And I set the chosen element "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_el_lang][und][]" to "EN"
    And I press the "Add another publication" button
    And I wait for AJAX to finish
    And I select "EAFRD Projects Brochure" from "field_enrd_sfr_pub_subcp_type[und][1][field_enrd_sfr_pub_subcp_typepub][und]"
    And I press the "field_enrd_sfr_pub_subcp_type_und_1_remove_button" button
    And I wait for AJAX to finish
    Then I should not see an "form-item-field-enrd-sfr-pub-subcp-type-und-1--weight" element
    # Test "X" (Remove copy) button for each Language(s) + N. of copies Double field.
    When I am at "enrd-sfr/add/enrd-sfr-pub-subscribe-cp"
    And I check the box "Paper version"
    And I select "PL" from "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_lng_cop][und][0][first]"
    And I select "5" from "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_lng_cop][und][0][second]"
    And I press "Add other language copies"
    And I wait for AJAX to finish
    And I select "FR" from "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_lng_cop][und][1][first]"
    And I select "1" from "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_lng_cop][und][1][second]"
    And I press the "field_enrd_sfr_pub_subcp_type_und_0_field_enrd_sfr_pub_subcp_lng_cop_und_0_remove_button" button
    And I wait for AJAX to finish
    Then I should see an "#edit-field-enrd-sfr-pub-subcp-type-und-0-field-enrd-sfr-pub-subcp-lng-cop-und-0" element
    But I should not see an "#form-item-field-enrd-sfr-pub-subcp-type-und-0-field-enrd-sfr-pub-subcp-lng-cop-und-1" element

  @anonymous @javascript @enrd-sfr @subscribe @cp
  Scenario: As Anonymous I get validation errors (also for the captcha) while filling in the form to subscribe to CP publications.
    Given I am an anonymous user
    When I am at "enrd-sfr/add/enrd-sfr-pub-subscribe-cp"
    And I check the box "Paper version"
    And I check the box "Electronic version"
    And I select "- Select a country -" from "Country"
    And I press the "Send request" button
    # Country, Address Line 1 and City should be required even if "Country" is not selected.
    Then I should see the following error messages:
      | error messages                                             |
      | Name field is required.                                    |
      | Surname field is required.                                 |
      | Email field is required.                                   |
      | Organisation field is required.                            |
      | Type of publication field is required.                     |
      | Language(s) + N. of copies field is required.              |
      | Language(s) field is required.                             |
      | Country field is required.                                 |
      | Address Line 1 field is required.                          |
      | City field is required.                                    |
      | What code is in the image? field is required.              |
      | You must agree with the ENRD Privacy Statement to proceed. |
    And I should not see the following error messages:
      | error messages                    |
      | Address Line 2 field is required. |
    # Fields should be required even if "Country" is selected (Addressfield default).
    And I select "Italy" from "Country"
    And I wait for AJAX to finish
    And I press the "Send request" button
    Then I should see the following error messages:
      | error messages                    |
      | Address Line 1 field is required. |
      | Postal code field is required.    |
      | City field is required.           |
      | Province field is required.       |
    And I should not see the following error messages:
      | error messages                    |
      | Address Line 2 field is required. |
    # Validate Postal code according to country.
    And I fill in "Postal code" with "ABCDE12345"
    And I press the "Send request" button
    Then I should see the following error message:
      | error messages                                                                            |
      | Invalid postal code. Postal codes in Italy, San Marino, and the Vatican are like "99999". |
    # The Name + Surname characters should totally count maximum 35.
    And I fill in "Name" with "BDD Very Long Name Example"
    And I fill in "Surname" with "BDD Very Long Surname Example"
    And I press the "Send request" button
    Then I should see the following error message:
      | error messages                                           |
      | Name + Surname should be maximum 35 characters in total. |

  @anonymous @javascript @enrd-sfr @subscribe @cp
  Scenario: Test custom validation errors while filling in the form to subscribe to CP publications.
    Given I am an anonymous user
    When I am at "enrd-sfr/add/enrd-sfr-pub-subscribe-cp"
    # I can specify the same Type only once.
    And I select "EU Rural Review" from "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_typepub][und]"
    And I check "Paper version"
    And I select "FR" from "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_lng_cop][und][0][first]"
    And I select "3" from "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_lng_cop][und][0][second]"
    And I press the "Add another publication" button
    And I wait for AJAX to finish
    And I select "EU Rural Review" from "field_enrd_sfr_pub_subcp_type[und][1][field_enrd_sfr_pub_subcp_typepub][und]"
    And I press the "Send request" button
    Then I should see the following error message:
      | error messages                                            |
      | Cannot enter the same Type of publication more than once. |
    # I have to specify at least paper or copy if Type is selected.
    And I uncheck "Paper version"
    And I press the "Send request" button
    Then I should see the following error message:
      | error messages                                                                                        |
      | You must specify if you wish to subscribe to paper or electronic (or both) for a Type of publication. |
    # I cannot enter the same language more than once.
    And I select "EAFRD Projects Brochure" from "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_typepub][und]"
    And I check "Paper version"
    And I select "DE" from "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_lng_cop][und][0][first]"
    And I select "3" from "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_lng_cop][und][0][second]"
    And I press the "Add other language copies" button
    And I wait for AJAX to finish
    And I select "DE" from "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_lng_cop][und][1][first]"
    And I select "5" from "field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_lng_cop][und][1][second]"
    And I press the "Add other language copies" button
    And I wait for AJAX to finish
    Then I should see the following error message:
      | error messages                                                       |
      | Cannot enter same Language for a Type of publication more than once. |

  @authenticated @enrd-sfr @subscribe @ehd @privacy
  Scenario: As Authenticated I want to fill in the form to subscribe to EHD publications, and I get Name, Surname and
  Email already pre-filled.
    Given I am logged in as a user with the "authenticated user" role and I have the following fields:
      | mail            | james.bond@example.com |
      | field_firstname | James                      |
      | field_lastname  | Bond                       |
    When I am at "evaluation/publications"
    And I click "Subscribe to Evaluation Publications"
    And I select "Researcher" from "Type of organisation"
    And I select "Belgium" from "Country"
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I press the "Send request" button
    Then I should see the message "Your submission request has been forwarded correctly."
    But I should not see the message "We have sent a confirmation email to the email address you have specified. Please open it and click on the link in order to finalize the request you have just submitted."
    # Test the destination parameter in the url.
    Then I should see the heading "Search Evaluation Publications"

  @authenticated @enrd-sfr @emails @subscribe @ehd @privacy
  Scenario: As Authenticated I want to fill in the form to subscribe to EHD publications, with an e-mail address
  different from that of the logged in user.
    Given I am logged in as a user with the "authenticated user" role and I have the following fields:
      | mail            | james.bond@example.com |
      | field_firstname | James                      |
      | field_lastname  | Bond                       |
    And the test email system is enabled
    When I am at "enrd-sfr/add/enrd-sfr-pub-subscribe-ehd"
    And I fill in "Email" with "another-email@example.com"
    And I select "Researcher" from "Type of organisation"
    And I select "Belgium" from "Country"
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I press the "Send request" button
    Then I should see the message "We have sent a confirmation email to the email address you have specified. Please open it and click on the link in order to finalize the request you have just submitted."
    But I should not see the message "Your submission request has been forwarded correctly."
    And I receive an email
    # Test the validation token link
    When I confirm the "another-email@example.com" through token link
    Then I should see the message "Your submission request has been forwarded correctly."

  @anonymous @enrd-sfr @subscribe @ehd
  Scenario: As Anonymous I get validation errors (also for the captcha) while filling in the form to subscribe to EHD publications.
    Given I am an anonymous user
    When I am at "enrd-sfr/add/enrd-sfr-pub-subscribe-ehd"
    And I press the "Send request" button
    Then I should see the following error messages:
      | error messages                                             |
      | Name field is required.                                    |
      | Surname field is required.                                 |
      | Email field is required.                                   |
      | What code is in the image? field is required.              |
      | You must agree with the ENRD Privacy Statement to proceed. |

  @authenticated @javascript @enrd-sfr @contact @cp @privacy
  Scenario: As Authenticated I want to fill in the form to be unsubscribed from CP publications, and I get Name, Surname and
  Email already pre-filled.
  I should not get a confirmation message to validate the e-mail (and the subscription request in turn).
    Given I am logged in as a user with the "authenticated user" role and I have the following fields:
      | mail            | jane.austen@example.com |
      | field_firstname | Jane                        |
      | field_lastname  | Austen                      |
    When I am at "enrd-sfr/add/enrd-sfr-pub-contact-cp"
    # Name, Surname, Email, Type of pub. & Paper/Electronic should be visible even if Reason is unselected
    # But the Addressfield should not be visible if Paper is not checked.
    Then I should see an "#edit-field-enrd-sfr-pub-contcp-reas" element
    And I should see an "#edit-field-enrd-sfr-pub-contcp-name" element
    And I should see an "#edit-field-enrd-sfr-pub-contcp-surn" element
    And I should see an "#edit-field-enrd-sfr-pub-contcp-email" element
    And I should see an "#edit-field-enrd-sfr-pub-contcp-papel" element
    And I should see an "#edit-field-enrd-sfr-pub-contcp-type" element
    But I should not see "Comments"
    But I should not see "Please specify how you would like to modify your subscription information"
    But I should not see "To what postal address do you currently receive the ENRD publications?"

    And I select "Unsubscribe" from "Reason"
    And I set the chosen element "field_enrd_sfr_pub_contcp_type[und][]" to "EU Rural Review"
    And I check "Electronic"
    Then I check "Paper"
    # Address Line 1 & Address Line 2 should have a maxlength description.
    And I should see "Maximum 35 characters." in the ".form-item-field-enrd-sfr-pub-contcp-oldadd-und-0-thoroughfare" element
    And I should see "Maximum 35 characters." in the ".form-item-field-enrd-sfr-pub-contcp-oldadd-und-0-premise" element
    # The Addressfield is visible if Paper is checked.
    And I select "Spain" from "Country"
    And I wait for AJAX to finish
    And I fill in "Address Line 1" with "Sample Street, 1"
    And I fill in "Address Line 2" with "Sample Street, 2"
    And I fill in "Postal code" with "12345"
    And I fill in "City" with "Alicante"
    And I select "Alicante" from "Province"
    And I fill in "Comments" with "These are BDD comments."
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I press the "Send request" button
    Then I should see the message "Your submission request has been forwarded correctly."
    But I should not see the message "We have sent a confirmation email to the email address you have specified. Please open it and click on the link in order to finalize the request you have just submitted."

    And I press "OK"
    And I select "Modify your subscriptions" from "Reason"
    And I set the chosen element "field_enrd_sfr_pub_contcp_type[und][]" to "EAFRD Projects Brochure"
    And I check "Electronic"
    And I fill in "Please specify how you would like to modify your subscription information" with "BDD Test modifications."
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I press the "Send request" button
    Then I should see the message "Your submission request has been forwarded correctly."
    But I should not see the message "We have sent a confirmation email to the email address you have specified. Please open it and click on the link in order to finalize the request you have just submitted."

    # Manage CP contact form requests as EHD user with webmaster role.
    Given I am logged in as a user with the "webmaster" role
    When I am at "admin/enrd/enrd-sfr/cp/contact"
    Then I should see the heading "CP contact form requests"
    When I select "Unsubscribe" from "Reason"
    And I press "Apply"
    Then I should see "Jane" in the "jane.austen@example.com" row
    And I should see "Austen" in the "jane.austen@example.com" row
    # Test the Contact forms "Export" functionality.
    And I check the box "edit-views-bulk-operations-0"
    And I press the "Export" button
    Then I should see "Choose fields to export"
    And I press "Next"
    And I wait for the batch job to finish
    Then I should see the heading "Data export successful"
    # Test the Contact "Delete" functionality.
    When I am at "admin/enrd/enrd-sfr/cp/contact"
    And I select "Modify your subscriptions" from "Reason"
    And I press "Apply"
    Then I check the box "edit-views-bulk-operations-0"
    And I press the "Delete" button
    And I press "Confirm"
    And I wait for the batch job to finish
    Then I should see the following success messages:
      | success messages            |
      | Performed Delete on 1 item. |
    And I should not see "jane.austen@example.com" in the "content" region

  @anonymous @javascript @enrd-sfr @contact @cp
  Scenario: As Anonymous I get validation errors (also for the captcha) while filling in the form to subscribe to CP publications.
    Given I am an anonymous user
    When I am at "enrd-sfr/add/enrd-sfr-pub-contact-cp"
    And I select "Unsubscribe" from "Reason"
    And I press the "Send request" button
    Then I should see the following error messages:
      | error messages                                                        |
      | Name field is required.                                               |
      | Surname field is required.                                            |
      | Email field is required.                                              |
      | Type of publication(s) field is required.                             |
      | Are you subscribed for electronic or paper copies? field is required. |
      | What code is in the image? field is required.                         |
      | You must agree with the ENRD Privacy Statement to proceed.            |
    And I should not see the following error messages:
      | error messages                                                                               |
      | Comments field is required.                                                                  |
      | Please specify how you would like to modify your subscription information field is required. |

    And I select "Modify your subscriptions" from "Reason"
    And I press the "Send request" button
    # Please specify how you would like to modify your subscription information required if Reason = Modify.
    Then I should see the following error message:
      | error messages                                                                               |
      | Name field is required.                                                                      |
      | Surname field is required.                                                                   |
      | Email field is required.                                                                     |
      | Type of publication(s) field is required.                                                    |
      | Are you subscribed for electronic or paper copies? field is required.                        |
      | What code is in the image? field is required.                                                |
      | You must agree with the ENRD Privacy Statement to proceed.                                   |
      | Please specify how you would like to modify your subscription information field is required. |
    And I should not see the following error messages:
      | error messages              |
      | Comments field is required. |

    # I should validation errors also when Reason is not selected.
    And I am at "enrd-sfr/add/enrd-sfr-pub-contact-cp"
    And I check "Paper"
    And I press the "Send request" button
    Then I should see the following error messages:
      | error messages                                             |
      | Reason field is required.                                  |
      | Name field is required.                                    |
      | Email field is required.                                   |
      | Surname field is required.                                 |
      | Type of publication(s) field is required.                  |
      | What code is in the image? field is required.              |
      | You must agree with the ENRD Privacy Statement to proceed. |
      | Country field is required.                                 |
      | Address Line 1 field is required.                          |
      | City field is required.                                    |
    But I should not see the following error messages:
      | error messages                                                                               |
      | Please specify how you would like to modify your subscription information field is required. |
      | Address Line 2 field is required.                                                            |
    And I select "Italy" from "Country"
    And I wait for AJAX to finish
    And I press the "Send request" button
    Then I should see the following error messages:
      | error messages                    |
      | Address Line 1 field is required. |
      | City field is required.           |
      | Province field is required.       |
    But I should not see the following error messages:
      | error messages                    |
      | Address Line 2 field is required. |
    # Validate Postal code according to country.
    And I fill in "Postal code" with "ABCDE12345"
    And I press the "Send request" button
    Then I should see the following error message:
      | error messages                                                                            |
      | Invalid postal code. Postal codes in Italy, San Marino, and the Vatican are like "99999". |

  @authenticated @javascript @enrd-sfr @contact @ehd @privacy
  Scenario: As Authenticated I want to fill in the form to ask for changing sub. data from EHD publications, and I get Name,
  Surname and Email already pre-filled.
  I should not get a confirmation message to validate the e-mail (and the subscription request in turn).
    Given I am logged in as a user with the "authenticated user" role and I have the following fields:
      | mail            | marie.curie@example.com |
      | field_firstname | Marie                       |
      | field_lastname  | Curie                       |
    When I am at "enrd-sfr/add/enrd-sfr-pub-contact-ehd"
    # Name, Surname & Email should be visible even if Action is unselected
    Then I should see an "#edit-field-enrd-sfr-pub-contehd-name" element
    Then I should see an "#edit-field-enrd-sfr-pub-contehd-surn" element
    Then I should see an "#edit-field-enrd-sfr-pub-contehd-email" element
    And I select "Modify your subscription" from "Action"
    And I fill in "Please specify how you would like to modify your subscription information" with "These are BDD requests of modifications."
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I press the "Send request" button
    Then I should see the message "Your submission request has been forwarded correctly."
    And I should not see the message "We have sent a confirmation email to the email address you have specified. Please open it and click on the link in order to finalize the request you have just submitted."
    When I am at "enrd-sfr/add/enrd-sfr-pub-contact-ehd"
    And I select "Unsubscribe" from "Action"
    And I fill in "Notes" with "These are BDD notes."
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I press the "Send request" button
    Then I should see the message "Your submission request has been forwarded correctly."
    And I should not see the message "We have sent a confirmation email to the email address you have specified. Please open it and click on the link in order to finalize the request you have just submitted."

    # Manage EHD contact form requests as EHD Manager.
    Given I am logged in as a user with the "ehd subscriptions manager" role
    When I am at "admin/enrd/enrd-sfr/ehd/contact"
    Then I should see the heading "Evaluation contact form requests"
    When I select "Unsubscribe" from "Action"
    And I press "Apply"
    Then I should see "Marie" in the "marie.curie@example.com" row
    And I should see "Curie" in the "marie.curie@example.com" row
    # Test the Contact forms "Export" functionality.
    And I check the box "edit-views-bulk-operations-0"
    And I press the "Export" button
    Then I should see "Choose fields to export"
    And I press "Next"
    And I wait for the batch job to finish
    Then I should see the heading "Data export successful"
    # Test the Contact "Delete" functionality.
    When I am at "admin/enrd/enrd-sfr/ehd/contact"
    And I select "Modify your subscription" from "Action"
    And I press "Apply"
    Then I check the box "edit-views-bulk-operations-0"
    And I press the "Delete" button
    And I press "Confirm"
    And I wait for the batch job to finish
    Then I should see the following success messages:
      | success messages            |
      | Performed Delete on 1 item. |
    And I should not see "marie.curie@example.com" in the "content" region

  @anonymous @enrd-sfr @contact @ehd
  Scenario: As Anonymous I get validation errors (also for the captcha) while filling in the form to subscribe to EHD publications.
    Given I am an anonymous user
    When I am at "enrd-sfr/add/enrd-sfr-pub-contact-ehd"
    And I select "Unsubscribe" from "Action"
    And I press the "Send request" button
    Then I should see the following error messages:
      | error messages                                             |
      | Name field is required.                                    |
      | Surname field is required.                                 |
      | Email field is required.                                   |
      | What code is in the image? field is required.              |
      | You must agree with the ENRD Privacy Statement to proceed. |
    And I should not see the following error messages:
      | error messages                                                                               |
      | Action field is required.                                                                    |
      | Please specify how you would like to modify your subscription information field is required. |

    And I select "Modify your subscription" from "Action"
    And I press the "Send request" button
    # Custom validation: Please specify... field is required only if Reason = Modify.
    Then I should see the following error message:
      | error messages                                                                               |
      | Name field is required.                                                                      |
      | Surname field is required.                                                                   |
      | Email field is required.                                                                     |
      | What code is in the image? field is required.                                                |
      | You must agree with the ENRD Privacy Statement to proceed.                                   |
      | Please specify how you would like to modify your subscription information field is required. |
    And I should not see the following error messages:
      | error messages            |
      | Action field is required. |

    # I should get validation errors even if no Action is selected.
    When I am at "enrd-sfr/add/enrd-sfr-pub-contact-ehd"
    And I press the "Send request" button
    Then I should see the following error messages:
      | error messages                                             |
      | Action field is required.                                  |
      | Name field is required.                                    |
      | Surname field is required.                                 |
      | Email field is required.                                   |
      | You must agree with the ENRD Privacy Statement to proceed. |
    When I am at "enrd-sfr/add/enrd-sfr-pub-contact-ehd"
    And I press the "Send request" button
    Then I should not see the following error messages:
      | error messages                                                                               |
      | Please specify how you would like to modify your subscription information field is required. |

  @javascript @ehd-subscriptions-manager @enrd-sfr @subscribe @ehd @privacy
  Scenario: As EHD Subscriptions manager I want to manage the Evaluation subscription requests.
    Given I am logged in as a user with the "ehd subscriptions manager" role and I have the following fields:
      | mail            | ehd.subs.manager@example.com |
      | field_firstname | John                             |
      | field_lastname  | Doe                              |
    When I am at "enrd-sfr/add/enrd-sfr-pub-subscribe-ehd"
    And I select "Austria" from "Country"
    And I check the box "eu_legal_notice"
    And I check the box "privacy_policy"
    And I press the "Send request" button
    And I am at "admin/enrd/enrd-sfr/ehd"
    Then I should see the heading "Evaluation subscription requests"
    # Note: .nav-tabs element available only if "Contact requests" is on.
    # And I should see "Subscription Requests" in the ".nav-tabs" element
    And I fill in "Name, Surname or E-mail contains" with "John"
    And I press "Apply"
    Then I should see "John" in the "ehd.subs.manager@example.com" row
    And I press "Reset"
    # Test the Subscriptions "Export" functionality.
    And I check the box "edit-views-bulk-operations-0"
    And I press the "Export" button
    Then I should see "Choose fields to export"
    And I press "Next"
    And I wait for the batch job to finish
    Then I should see the heading "Data export successful"
    # Test the Subscriptions "Delete" functionality.
    And I click "Return to previous page"
    And I check the box "edit-views-bulk-operations-0"
    And I press the "Delete" button
    And I press "Confirm"
    And I wait for the batch job to finish
    Then I should see the following success messages:
      | success messages            |
      | Performed Delete on 1 item. |
    And I should not see "ehd.subs.manager@example.com" in the "content" region
