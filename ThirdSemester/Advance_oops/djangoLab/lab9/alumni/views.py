from django.shortcuts import render
from django.views.generic import TemplateView
# Create your views here.


class Index(TemplateView):
    def get(self, request, *args, **kwargs):
        return render(request, 'index.html', {'college': 'rvce'})


class Display(TemplateView):
    def get(self, request, *args, **kwargs):
        usn = request.GET['usn']
        name = request.GET['name']
        address = request.GET['address']

        return render(request, 'display.html', {'usn': usn, 'name': name, 'address': address})
