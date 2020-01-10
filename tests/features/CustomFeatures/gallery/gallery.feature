@api @gallery
Feature: ENRD Gallery.
  This Feature aims at creating media galleries to include photos and videos about different topics, each of which can be embedded in other site contents through every textarea field for which it is enabled the NextEuropa Token CKEditor plugin.
  For this purpose, it creates a custom Gallery content type to include Media Files.

  @anonymous @javascript @test
  Scenario: As Anonymous I can see the Gallery fields.
    Given I am an anonymous user
    And an image "bdd-image.jpg" with the caption "BDD Image caption"
    And a video "bdd-video.mp4" with the description "BDD Video description"

    And I am viewing a "gallery" content in "published" status:
      | title                            | BDD Media Gallery                     |
      | created                          | 01-01-2019 8:00                       |
      | language                         | en                                    |
      | body                             | This is the body of a Media Gallery.  |
      | field_enrd_gallery_media         | bdd-image.jpg, bdd-video.mp4          |

    Then I should see the heading "BDD Media Gallery"
    And I should see the text "This is the body of a Media Gallery."
    # Test that files are visible.
    And I should see an "div.file-image-jpeg" element
    And I should see an "div.file-video-mp4" element
    # Test Image Caption and Video Description.
    And I should see the "a.media-colorbox" element with the "title" attribute set to "BDD Image caption" in the "content" region
    And I should see the "a.media-colorbox" element with the "title" attribute set to "BDD Video description" in the "content" region

  @javascript @admin @editor @contributor
  Scenario Outline: As Admin, Editor and Contributor I want to embed a gallery into my basic page.
    However, I should only see a max of 4 media files in the embedded Gallery display.
    Given an image "test-image-1.jpg" with the caption "Mickey Mouse"
    And an image "test-image-2.jpg" with the caption "Minnie Mouse"
    And an image "test-image-3.jpg" with the caption "Donald Duck"
    And an image "test-image-4.jpg" with the caption "Goofy"
    And an image "test-image-5.jpg" with the caption "Pluto"
    And I am viewing a "gallery" content in "published" status:
      | title                    | BDD Embedded Gallery                 |
      | body                     | This is the body of a Media Gallery. |
      | field_enrd_gallery_media | test-image-1.jpg, test-image-2.jpg, test-image-3.jpg, test-image-4.jpg, test-image-5.jpg   |

    Given I am logged in as a user with the "<role>" role
    And I am creating a "page" content
    And I fill in "edit-title-field-en-0-value" with "BDD Test page to embed Gallery"
    When I click the "Insert internal content" button in the "Body" WYSIWYG editor
    Then I follow "Insert Media Galleries"
    And I click "Embedded Media Gallery" in the "BDD Embedded Gallery" row
    And I wait for AJAX to finish
    And I press "Save"
    Then I should see the "a.media-colorbox" element with the "title" attribute set to "Mickey Mouse" in the "content" region
    And I should see the "a.media-colorbox" element with the "title" attribute set to "Minnie Mouse" in the "content" region
    And I should see the "a.media-colorbox" element with the "title" attribute set to "Donald Duck" in the "content" region
    And I should see the "a.media-colorbox" element with the "title" attribute set to "Goofy" in the "content" region
    But I should not see "Pluto" in the "a.media-colorbox" element
    And I click "See more" in the "content" region
    Then I should see the heading "BDD Embedded Gallery"

    Examples:
      | role          |
      | administrator |
      | contributor   |
      | editor        |
