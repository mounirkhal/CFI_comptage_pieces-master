pipeline
{
agent any
      tools{
      maven 'apache-maven-3.6.3'
      jdk 'jdk-11.0.5'
      }
      stages{
              stage('build')
              {
                 steps{
                 bat 'mvn compiller:compile'
                 }
                 post
                 {
                    success{
                    echo 'projet compilé avec succès'
                           }
                           
                    faillure{ 
                    echo 'Erreur de compilation'
                    }
                }
                 
              }
      }
}
