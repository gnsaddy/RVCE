from django.shortcuts import render, redirect
from django.views.generic import TemplateView
from src.models import Emp


class Index(TemplateView):
    template_name = 'index.html'


class Insert(TemplateView):
    def get(self, request, **kwargs):
        eid = request.GET['eid']
        name = request.GET['name']
        age = request.GET['age']
        address = request.GET['address']
        d = Emp(eid=eid, name=name, age=age, address=address)
        d.save()
        return redirect('show')


def show(request):
    shelf = Emp.objects.all()
    return render(request, 'display.html', {'shelf': shelf})
