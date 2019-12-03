from django.shortcuts import render

from django.shortcuts import render
from django.views.generic import TemplateView


class Registration(TemplateView):
    def get(self, request, *args, **kwargs):
        return render(request, 'registration.html', {'college': 'RVCE'})


class Display(TemplateView):
    def get(self, request, *args, **kwargs):
        usn = request.GET['usn']
        name = request.GET['name']
        address = request.GET['address']

        return render(request, 'display.html', {'USN': usn, 'Name': name, 'address': address})
