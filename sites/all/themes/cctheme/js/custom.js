jQuery( document ).ready(function () {
    jQuery('#login-area-toggle').click(function () {
        jQuery(this).toggleClass('active');
        jQuery('.region-area-top .header-login').slideToggle('normal', function () {});
        jQuery('.region-area-top .header-login >.block-inner').fadeToggle('slow');
    });



    jQuery('#panel-first-wrapper .block-inner').click(function(){
        window.location.href = jQuery(this).find('.block-content a').attr('href');
    });

    if(!jQuery('body').hasClass('page-forum')){
        jQuery('select').css({'width': '200px'}).select2();

    }


    if(jQuery('body').hasClass('page-node-add-case-tracker')){
        jQuery('.form-item-casetracker-case-type-id').insertAfter('.form-item-title');
    }
});