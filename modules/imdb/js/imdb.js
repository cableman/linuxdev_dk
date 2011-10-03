(function ($) {
  $(document).ready(function() {
    button = $('<button id="imdb-button" type="button">Use IMDB</button>')
    $('#edit-field-imdb-id-und-0-value').parent().append(button);
    button.show();

    if ($('#edit-field-poster img').length) {
      $('#edit-field-poster-und-0-value').hide();
    }

    // Add click action
    button.click(function () {
      $(this).attr("disabled", "true");
      id = $('#edit-field-imdb-id-und-0-value').val();
      $.get('/callback/imdb/'+id, function(response) {
        imdb = jQuery.parseJSON(response);

        // Fill out the form.
        $('#edit-title').val(imdb.data.Title);
        $('#edit-field-year-und-0-value-date').val(imdb.data.Year);
        $('#edit-field-reated-und-0-value').val(imdb.data.Rated);
        $('#edit-field-released-und-0-value-date').val(imdb.data.Released);
        $('#edit-field-genre-und').val(imdb.data.Genre);
        $('#edit-field-directors-und').val(imdb.data.Director);
        $('#edit-field-writers-und').val(imdb.data.Writer);
        $('#edit-field-actors-und').val(imdb.data.Actors);
        $('#edit-field-plot-und-0-value').val(imdb.data.Plot);

        // Add post location.
        $('#edit-field-poster-und-0-value').val(imdb.data.Poster);

        // Insert thumbnail.
        if ($('#edit-field-poster img').length) {
          $('#edit-field-poster img').hide();
        }
        $('#edit-field-poster-und-0-value').parent().append(imdb.data.Thumbnail);
        $('#edit-field-poster-und-0-value').hide();


        $('#edit-field-runtime-und-0-value').val(imdb.data.Runtime);
        $('#edit-field-rating-und-0-value').val(imdb.data.Rating);
        $('#edit-field-votes-und-0-value').val(imdb.data.Votes);


        $('#imdb-button').removeAttr("disabled");
      });
    });
  });
})(jQuery);