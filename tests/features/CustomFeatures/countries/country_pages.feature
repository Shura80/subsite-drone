@api @country_pages
Feature: ENRD Country Pages

  This feature is aimed at creating the RDP information content type and its related configurations. The RDP information
  content type is used to implement the European Union Country pages, which expose information both at national and
  regional level, depending on the country.

  @anonymous
  Scenario: As anonymous I can see a subset of RDP information fields, both at national and regional level.
    Given: I am an anonymous user
    And 'enrd_countries' terms:
      | name           | parent         |
      | European Union | Europe         |
      | BDD Italy      | European Union |
      | BDD Abruzzo    | BDD Italy      |

    And I am viewing a "rdp_information" content in "published" status:
      | title                            | BDD Custom RDP information                   |
      | field_enrd_rdp_info_intro_text   | BDD National Introductory text               |
      | field_enrd_rdp_info_country      | BDD Italy                                    |
      | field_enrd_rdp_info_rdp_docs     | BDD National RDP documents sample text       |
      | field_enrd_rdp_info_partner_docs | BDD National Partnership Agreement documents |
      | field_enrd_rdp_info_nrn_info     | BDD National NRN Information                 |
      | field_enrd_rdp_info_nation_auth  | BDD National Managing Authority              |
      | field_enrd_rdp_info_nat_pay_agen | BDD National Paying Agency                   |

    And I create the following "field_enrd_rdp_info_region" field collection
      | field_enrd_rdp_info_region_name  | BDD Abruzzo                     |
      | field_enrd_rdp_info_region_intro | BDD Regional Introductory text  |
      | field_enrd_rdp_info_region_docs  | BDD Regional RDP documents      |
      | field_enrd_rdp_info_region_nrn   | BDD Regional NRN Information    |
      | field_enrd_rdp_info_region_auth  | BDD Regional Managing Authority |
      | field_enrd_rdp_info_region_pay   | BDD Regional Paying Agency      |

    # I want to see the National fields for the Country pages.
    And I should see the text "BDD Italy"
    And I should see the text "BDD National Introductory text"
    And I should see the text "BDD National RDP documents sample text"
    And I should see the text "BDD National Partnership Agreement documents"
    And I should see the text "BDD National NRN Information"
    And I should see the text "BDD National Managing Authority"
    And I should see the text "BDD National Paying Agency"

    # I want to see the Regional fields for the Country pages.
    And I should see the text "BDD Abruzzo"
    And I click "BDD Abruzzo"
    And I should see the text "BDD Regional Introductory text"
    And I should see the text "BDD Regional RDP documents"
    And I should see the text "BDD Regional NRN Information"
    And I should see the text "BDD Regional Managing Authority"
    And I should see the text "BDD Regional Paying Agency"

  @anonymous @wip
  # This scenario should be readapted to work with Media image fields.
  Scenario: As Anonymous I want to see both the national and the regional country images from the RDP information page.
    Given: I am an anonymous user
    And I am viewing an "rdp_information" content in "published" status:
      | title | BDD Test media RDP information |

    Given I am logged in as a user with the "administrator" role
    And I am on "country/bdd-test-media-rdp-information"
    And I click "New draft"
    # National NRN image.
    And I attach the file "bdd-image.jpg" to "media[field_rdp_info_nrn_image_und_0]"
    # Regional NRN image.
    And I attach the file "bdd-image.jpg" to "media[field_enrd_rdp_info_region_und_0_field_enrd_rdp_info_region_image_und_0]"
    And I press "Save"
    Then I should see the heading "BDD Test media RDP information"
    And I should see the "field-name-field-rdp-info-nrn-image" element in the "content" region
    And I should see the "field-name-field-enrd-rdp-info-region-image" element in the "content" region

  @editor @workflow @moderate-all
  Scenario: As editor I want to create a new RDP information as well as edit and moderate an RDP information not created by me.
    Given I am logged in as a user with the "editor" role
    When I click "Create content"
    Then I should see the link "Country Information"
    And I should be able to edit a "Country Information" content

    When I am viewing an "rdp_information" content in "needs_review" status:
      | title | BDD editor RDP information title |
    And I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Validated" in the "BDD editor RDP information title" row
    Then I should see the text "Validated" in the "BDD editor RDP information title" row

  @contributor @workflow @moderate-all
  Scenario: As contributor I cannot neither edit an RDP information other than mine nor moderate it.
    Given I am logged in as a user with the "contributor" role
    Then I should not be able to edit a "Country Information" content

    When I am viewing an "rdp_information" content in "draft" status:
      | title | BDD contributor RDP information title |
    And I go to "admin/workbench"
    And I click "Moderate All"
    And I click "Change to Needs Review" in the "BDD contributor RDP information title" row
    Then I should get a 403 HTTP response

  @anonymous @lang-selection
  Scenario: As Anonymous I want to see an RDP information page translated into Italian.
    Given I am an anonymous user
    And I am viewing a multilingual "rdp_information" content:
      | language | title                  |
      | en       | BDD example in English |
      | it       | BDD example in Italian |
    When I follow "Italiano"
    Then I should see the heading "BDD example in Italian"
    When I follow "English"
    Then I should see the heading "BDD example in English"
