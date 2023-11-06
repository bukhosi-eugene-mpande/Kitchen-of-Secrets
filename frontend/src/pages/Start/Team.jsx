import MeetTeam from '../assets/img/MeetTeam.jpg';
import React from 'react';
import 'bootstrap/dist/css/bootstrap.min.css'; // Import Bootstrap CSS
import { Card } from 'react-bootstrap'; // Import Bootstrap Card components

//team images
import Ashley from '../assets/img/ashley.jpg';
import Ayanda from '../assets/img/ayanda.jpg';
import Joshua from '../assets/img/josh.jpg';
import Eugene from '../assets/img/eugene.jpg';
import Chenoa from '../assets/img/chenoa.jpg';
import Thato from '../assets/img/thato.jpg';

const teamMembers = [
  {
    name: 'Ashley Kapaso',
    role: 'Team Leader',
    image: Ashley,
  },
  {
    name: 'Ayanda Juqu',
    role: 'Team Leader',
    image: Ayanda,
  },
  {
    name: 'Joshua Wereley',
    role: 'Management System',
    image: Joshua,
  },
  {
    name: 'Eugene Mpande',
    role: 'Team Leader',
    image: Eugene,
  },
  {
    name: 'Chenoa Perkett',
    role: 'Team Leader',
    image: Chenoa,
  },
  {
    name: 'Thato Kalagobe',
    role: 'Reservations & Frontend',
    image: Thato,
  },
];

const Team = () => {
  return (
    <div className="team" style={team}>
      <h2 className='mt-5'>Meet our Team</h2>
     
      <div className="team-container text-center justify-content-center container">
        <div className="card-deck row">

            <Card className="col-3" style={{ backgroundColor: 'white'}}>
              <img src={Ashley} alt='Ashley' width='150px' style={{borderRadius:'5%'}} className='justify-content-center mt-3 ml-1'/>
              <Card.Body>
                <Card.Title>Ashley Kapaso</Card.Title>
                <Card.Text>Accounting & System Integration</Card.Text>
              </Card.Body>
            </Card>

            <Card className="col-3" style={{ backgroundColor: 'white' }}>
              <img src={Ayanda} alt='Ayanda' width='150px' style={{borderRadius:'5%'}} className='justify-content-center mt-3 ml-1'/>
              <Card.Body>
                <Card.Title>Ayanda Juqu</Card.Title>
                <Card.Text>Ordering & System Intergration</Card.Text>
              </Card.Body>
            </Card>

            <Card className="col-3" style={{ backgroundColor: 'black', color:'white' }}>
              <img src={Joshua} alt='Joshua' width='150px' style={{borderRadius:'5%'}} className='justify-content-center mt-3 ml-1' />
              <Card.Body>
                <Card.Title>Joshua Wereley</Card.Title>
                <Card.Text>Team Leader - Management & System Integration</Card.Text>
              </Card.Body>
            </Card>

            <Card className="col-3" style={{ backgroundColor: 'black', color:'white' }}>
              <img src={Eugene} alt='Eugene' width='150px' style={{borderRadius:'5%'}} className='justify-content-center mt-3 ml-1'/>
              <Card.Body>
                <Card.Title>Eugene Mpande</Card.Title>
                <Card.Text>Team Leader - Kitchen & System Integration</Card.Text>
              </Card.Body>
            </Card>

            <Card className="col-3" style={{ backgroundColor: 'white' }}>
              <img src={Chenoa} alt='Chenoa' width='150px' style={{borderRadius:'5%'}} className='justify-content-center mt-3 ml-1'/>
              <Card.Body>
                <Card.Title>Chenoa Perkett</Card.Title>
                <Card.Text>CustomerCare & Frontend</Card.Text>
              </Card.Body>
            </Card>

            <Card className="col-3" style={{ backgroundColor: 'white' }}>
              <img src={Thato} alt='Thato' width='150px' style={{borderRadius:'5%'}} className='justify-content-center mt-3 ml-1'/>
              <Card.Body>
                <Card.Title>Thato Kalagobe</Card.Title>
                <Card.Text>Reservations & Frontend</Card.Text>
              </Card.Body>
            </Card>
        </div>
      </div>
    </div>
  );
};

const getCardBackgroundColor = (name) => {
  // Check if the name matches the conditions for purple background
  if (name === 'Eugene Mpanza' || name === 'Joshua Wereley') {
    return 'purple'; // Set the background color to purple
  }
  return ''; // Default background color
};

const team = {
  backgroundImage: `url(${MeetTeam})`,
  backgroundRepeat: 'no-repeat',
  backgroundSize: 'cover',
  height: '100vh',
  display: 'flex',
  flexDirection: 'column',
  flexWrap: 'wrap',
  alignItems: 'center',
  justifyContent: 'center',
};

export default Team;
