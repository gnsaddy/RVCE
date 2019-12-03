from django.shortcuts import render
from django.shortcuts import redirect, render
from django.views.generic import TemplateView
from src.models import Emp
from src.forms import CreateEmp
from django.http import HttpResponse

# Create your views here.


class HomePage(TemplateView):
    template_name = 'index.html'


def upload(request):
    upload = CreateEmp()
    if request.method == 'POST':
        upload = CreateEmp(request.POST, request.FILES)
        if upload.is_valid():
            upload.save()
            return redirect('index')
        else:
            return HttpResponse("""your form is wrong, reload on <a href = "{{ url : 'index'}}">reload</a>""")
    else:
        return render(request, 'insert.html', {'upload_form': upload})


def display(request):
    shelf = Emp.objects.all()
    return render(request, 'display.html', {'shelf': shelf})
