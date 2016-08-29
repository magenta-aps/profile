<div class="layout-default-inverted">
  <div class="layout--inner">
    <div class="layout-element-alpha">
      <?php include('inc/block-user-links.inc') ?>
      <?php include('inc/block-my-content.inc') ?>
    </div>
    <div class="layout-element-beta">
      <h1>Edit user profile</h1>
      <fieldset class="user-profile-module--field-group-fieldset">
        <legend class="fieldset-legend">Personlige informationer</legend>
        <div class="form-item">
          <label>Fornavn</label>
          <input type="text" value="Lars" class="form-text" id="first-name" required>
        </div>
        <div class="form-item">
          <label>Efternavn</label>
          <input type="text" value="Larsen" class="form-text" id="last-name" required>
        </div>
      </fieldset>
      <fieldset class="user-profile-module--field-group-fieldset">
        <legend class="fieldset-legend">Arbejdsrelaterede informationer</legend>
        <div class="form-item">
          <label>Jobtitel</label>
          <input type="text" value="Administrativ medarbejder " class="form-text" required>
        </div>
        <div class="form-item">
          <label>Profession</label>
          <input type="text" value="Sosu-hjælper" class="form-text" required>
        </div>
        <div class="form-item">
          <label>Lokation</label>
          <input type="text" value="Lokation" class="form-text" required>
        </div>
      </fieldset>
      <div class="form-item form-type-textarea">
        <label for="question-textarea">Beskrivelse<span class="form-required">*</span></label>
        <textarea class="form-textarea" required>Lorem ipsum dolor sit amet, consectetur adipisici elit, sed eiusmod tempor incidunt ut labore et dolore magna aliqua. Ab illo tempore, ab est sed immemorabili. Unam incolunt Belgae, aliam Aquitani, tertiam.
        </textarea>
      </div>
      <fieldset id="edit-picture" class="field-group-fieldset edit-user--image-fieldset">
        <legend class="fieldset-legend">Picture</legend>
        <img width="500" height="500" title="testuser3's picture" alt="testuser3's picture" src="http://loop.etek.dk/sites/loop.etek.dk/files/styles/profile/public/pictures/picture-6-1392707743.png?itok=oT7mVmo-" class="edit-user--image">
        <div class="edit-user--image-buttons">
          <input type="submit" value="Slet billede" class="edit-user--image-button-remove">
          <input type="submit" value="Upload nyt" class="edit-user--image-button-add">
        </div>
      </fieldset>
      <div class="form-actions">
        <input type="submit" value="Gem" class="form-submit">
        <input type="submit" value="Slet" class="form-submit">
      </div>
    </div>
  </div>
</div>