from flask import Flask, render_template,make_response
import pdfkit

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')


@app.route('/save')
def save():

    options = {
    'page-size': 'A4',
    'margin-top': '0',
    'margin-right': '0',
    'margin-bottom': '0',
    'margin-left': '0',
    'encoding': "UTF-8",
    'no-outline': None,
    'quiet': ''
    }
    rendered = render_template("index.html")
    css = ['static/resume.css']
    pdf = pdfkit.from_string(rendered, False, css = css, options = options)
    response = make_response(pdf)
    response.headers['Content-Type'] = 'application/pdf'
    response.headers['Content-Disposition'] = 'attachment; filename = cv.pdf'

    return response



@app.route('/pdf')
def pdf_index():
    options = {
    'page-size': 'A4',
    'margin-top': '0',
    'margin-right': '0',
    'margin-bottom': '0',
    'margin-left': '0',
    'encoding': "UTF-8",
    'no-outline': None,
    'quiet': ''
    }
    rendered = render_template("index.html")
    css = ['static/resume.css']
    pdf = pdfkit.from_string(rendered, False, css = css, options = options)

    response = make_response(pdf)
    response.headers['Content-Type'] = 'application/pdf'
    response.headers['Content-Disposition'] = 'inline; filename = cv.pdf'

    return response
   
if __name__=="__main__":
    app.run(debug=True)
