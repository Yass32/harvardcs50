//Function to add in a fading effect when a nav link is clicked

document.addEventListener('DOMContentLoaded', function() {
    document.getElementById("about").addEventListener("click", function(event) {
        event.preventDefault();
        document.body.classList.add("page-transition");
        setTimeout(function() {
          window.location.href = "index.html";
        }, 1000);
    });

    document.getElementById("experience").addEventListener("click", function(event) {
        event.preventDefault();
        document.body.classList.add("page-transition");
        setTimeout(function() {
          window.location.href = "Experience.html";
        }, 1000);
    });

    document.getElementById("education").addEventListener("click", function(event) {
        event.preventDefault();
        document.body.classList.add("page-transition");
        setTimeout(function() {
          window.location.href = "Education.html";
        }, 1000);
    });

    document.getElementById("skills").addEventListener("click", function(event) {
        event.preventDefault();
        document.body.classList.add("page-transition");
        setTimeout(function() {
          window.location.href = "Skills.html";
        }, 1000);
    });

    document.getElementById("projects").addEventListener("click", function(event) {
        event.preventDefault();
        document.body.classList.add("page-transition");
        setTimeout(function() {
          window.location.href = "Projects.html";
        }, 1000);
    });

    document.getElementById("certifications").addEventListener("click", function(event) {
        event.preventDefault();
        document.body.classList.add("page-transition");
        setTimeout(function() {
          window.location.href = "Certifications.html";
        }, 1000);
    });
});