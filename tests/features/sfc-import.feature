@SFC @api
Feature: Test SFC project import

  Scenario: Check the SFC projects import forms structure
    Given I am logged in as a user with the "administrator" role
    When I am at "sfc-projects"
    # Moderate SFC projects
    Then I should see "Moderate SFC projects" in the ".tabs-primary" element
    And I should see the link "Import projects"
    And I should see the link "Load final report"
    And I should see the link "Manage Projects"
    And I should have the following options for "Main funding source":
      | options                                                                                      |
      | Rural development 2014-2020 for Operational Groups (in the sense of Art 56 of Reg.1305/2013) |
      | Horizon 2020 (EU Research & Innovation programme)                                            |
    # Import projects
    When I click "Import projects"
    Then I should see "Choose type"
    And I should see "zip file" in the ".form-type-radios" element
    And I should see "xls file" in the ".form-type-radios" element
    When I select the radio button "zip file" with the id "edit-extension-zip"
    Then I should see an "#edit-file-zip" element
    But I should not see an "Projects xls file " element
    When I select the radio button "xls file" with the id "edit-extension-xls"
    Then I should see an "#edit-file-xls" element
    But I should not see an "Projects zip file " element
    # Final report tab
    When I click "Load final report"
    Then I should have the following options for "edit-status":
      | options |
      | Yes     |
      | No      |
    And I should see the "#edit-field-project-puid-value" element in the "content"
    And I should see the button "Apply"
    And I should see the "#edit-actionviews-bulk-operations-modify-action" element in the "content"
    # Manage projects tab
   When I click "Manage Projects"
    Then I should see "PUID (Project Unique ID)"
    Then I should see "Title contains"
    Then I should see "Is published"
    Then I should see "Has hidden Partners"
    Then I should see "Main funding source"
    Then I should see "Geographical location"

  @javascript
  Scenario: Test the SFC projects check on empty or invalid uploaded templates
    Given I am logged in as a user with the "administrator" role
    When I am at "sfc-projects/import"
  # No zip file
    When I select the radio button "zip file" with the id "edit-extension-zip"
    Then I should see "Projects ZIP file"
    When I press the "Import" button
    Then I should see the following error message:
      | error messages       |
      | No file was uploaded |
  # No xls files in extracted zip
    When I select the radio button "zip file" with the id "edit-extension-zip"
    And I attach the file "sfc_test_NO_XLS.zip" to "edit-file-zip"
    When I press the "Import" button
    Then I should see the following warning messages:
      | warning messages                        |
      | No SFC template found in uploaded files |
  # No xls file
    When I select the radio button "xls file" with the id "edit-extension-xls"
    Then I should see "Projects xls file"
    When I press the "Import" button
    Then I should see the following error message:
      | error messages       |
      | No file was uploaded |
  # Simulate SFC projects import process
    When I am at "sfc-projects/import"
    And I select the radio button "xls file" with the id "edit-extension-xls"
    And I attach the file "sfc_test_TEMPLATE.xls" to "edit-file-xls"
    And I check the box "Simulate the process"
    And I press the "Import" button
    And I wait for the batch job to finish
    Then I should see the following warning messages:
      | warning messages                                                              |
      | One or more fields caused errors during import process. See the details page. |
    And I should see the following success messages:
      | success messages      |
      | Simulation completed. |
    # Test the SFC projects single file and archive import functionality
    # Successful import of an xls file
    When I am at "sfc-projects/import"
    And I select the radio button "xls file" with the id "edit-extension-xls"
    And I attach the file "sfc_test_TEMPLATE.xls" to "edit-file-xls"
    And I press the "Import" button
    And I wait for the batch job to finish
    Then I should see the following success messages:
      | success messages           |
      | Data uploaded successfully |
    # Successful import of a zip archive
    When I am at "sfc-projects/import"
    And I select the radio button "zip file" with the id "edit-extension-zip"
    And I attach the file "sfc_test_TEMPLATES.zip" to "edit-file-zip"
    And I press the "Import" button
    And I wait for the batch job to finish
    Then I should see the following success messages:
      | success messages           |
      | Data uploaded successfully |
    # Test the visibility of SFC logs page for administrators
    When I am at "admin/reports/sfc-importer/log"
    And I press the "Clear all messages" button
    And I press the "Yes, delete all" button
    Then I should see the following success messages:
      | success messages                |
      | All messages have been deleted. |
