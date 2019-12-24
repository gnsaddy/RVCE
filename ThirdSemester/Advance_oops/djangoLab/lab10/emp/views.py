from django.shortcuts import render, redirect
from django.views.generic import TemplateView
from emp.models import Emp
from emp.forms import CreateForm
from django.http import HttpResponse


class Index(TemplateView):
    template_name = 'index.html'


def upload(request):
    upload = CreateForm()
    if request.method == 'POST':
        upload = CreateForm(request.POST)
        if upload.is_valid():
            upload.save()
            return redirect('display')
        else:
            return redirect('display')
    else:
        return render(request, 'insert.html', {'upload': upload})


def display(request):
    shelf = Emp.objects.all()
    return render(request, 'display.html', {'shelf': shelf})
