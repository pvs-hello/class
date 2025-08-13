pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                // This just uses Jenkins' built-in checkout from SCM
                checkout scm
            }
        }

        stage('Install Dependencies') {
            steps {
                sh '''
                    # Create virtual environment
                    python3 -m venv venv
                    # Activate it
                    . venv/bin/activate
                    # Upgrade pip
                    pip install --upgrade pip
                    # Install required packages
                    pip install -r requirements.txt
                '''
            }
        }

        stage('Run Tests') {
            steps {
                sh '''
                    # Activate venv and run pytest
                    . venv/bin/activate
                    pytest --html=reports/index.html
                '''
            }
        }

        stage('Publish Report') {
            steps {
                publishHTML(target: [
                    allowMissing: false,
                    alwaysLinkToLastBuild: true,
                    keepAll: true,
                    reportDir: 'reports',
                    reportFiles: 'index.html',
                    reportName: 'Test Report'
                ])
            }
        }
    }
}